#pragma once
#include <map>
#include <set>
#include <string>
#include <string_view>
#include <vector>

class Information {
public:
    Information(const std::string_view key, const std::string_view val)
        : key_(key)
        , val_(val){};

public:
    bool operator<(const Information& other) const
    {
        return this->key_ < other.key_;
    }

    std::string_view key(void) const { return this->key_; };
    std::string_view val(void) const { return this->val_; };

private:
    std::string_view key_;
    std::string_view val_;
};

std::set<std::string_view> make_infokey_set(const std::vector<std::vector<std::string>>& clinets_info_keys)
{
    std::set<std::string_view> infokey_set;

    for (const auto& clinet_infos : clinets_info_keys) {
        for (const auto& info : clinet_infos) {
            infokey_set.insert(std::string_view(info.data()));
        }
    }

    return infokey_set;
}

std::string make_query(const std::string_view TN, const std::set<std::string_view>& info_key_set)
{
    auto info_size = 0;
    for (const auto& info : info_key_set) {
        info_size += info.size() + 2;
    }

    auto TN_size = TN.size();
    constexpr auto others_size = 15;

    const auto expected_size = info_size + TN_size + others_size;

    std::string str;
    str.reserve(expected_size);

    str += "create table ";
    str += TN;
    str += " (";

    for (const auto& info : info_key_set) {
        str += info;
        str += ", ";
    }

    str.pop_back();
    str.pop_back();
    str += ")";

    return str;
}

std::vector<std::string> make_insert_query(const std::string_view TN, const std::vector<std::set<Information>>& clients_keyval_set)
{
    const auto num_clients = clients_keyval_set.size();

    std::vector<std::string> result;
    result.reserve(num_clients);

    for (const auto& keyval_set : clients_keyval_set) {
        auto key_str_size = 0;
        auto val_str_size = 0;

        constexpr auto delimiter_size = 2;
        for (const auto& keyval : keyval_set) {
            key_str_size += keyval.key().size() + delimiter_size;
            val_str_size += keyval.val().size() + delimiter_size;
        }

        auto TN_size = TN.size();
        constexpr auto others_size = 15;

        const auto expected_size = key_str_size + val_str_size + TN_size + others_size;

        std::string insert_query;
        insert_query.reserve(expected_size);

        insert_query += "insert into ";
        insert_query += TN;
        insert_query += " ";

        std::string key_str = "(";
        std::string val_str = "values (";
        key_str.reserve(key_str_size);
        val_str.reserve(val_str_size);

        for (const auto& keyval : keyval_set) {
            key_str += keyval.key();
            key_str += ", ";
            val_str += keyval.val();
            val_str += ", ";
        }

        key_str.pop_back();
        key_str.pop_back();
        key_str += ")";

        val_str.pop_back();
        val_str.pop_back();
        val_str += ")";

        insert_query.append(key_str);
        insert_query += " ";
        insert_query.append(val_str);

        result.push_back(std::move(insert_query));
    }

    return result;
}

std::vector<std::set<Information>> make_clients_information_set(const std::vector<std::vector<std::string>>& clinets_info_keys, const std::vector<std::vector<std::string>>& clinets_info_vals)
{
    const auto num_clients = clinets_info_keys.size();

    std::vector<std::set<Information>> result;
    result.reserve(num_clients);

    for (int i = 0; i < num_clients; ++i) {
        const auto& client_info_keys = clinets_info_keys[i];
        const auto& client_info_vals = clinets_info_vals[i];

        const auto num_key = client_info_keys.size();

        std::set<Information> information_set;
        for (int j = 0; j < num_key; ++j) {
            information_set.insert(Information(client_info_keys[j], client_info_vals[j]));
        }

        result.push_back(std::move(information_set));
    }

    return result;
}

class DB {
public:
    DB(const std::vector<std::vector<std::string>>& clinets_info_keys, const std::vector<std::vector<std::string>>& clinets_info_vals)
    {
        constexpr auto initial_val = 0;

        for (const auto& clinet_infos : clinets_info_keys) {
            for (const auto& info : clinet_infos) {
                this->key_to_var_index_.emplace(std::string_view(info.data()), initial_val);
            }
        }

        auto index = 0;
        for (auto& [key, val] : this->key_to_var_index_) {
            val = index++;
        }

        const auto num_clients = clinets_info_keys.size();
        const auto num_total_key = this->key_to_var_index_.size();

        this->clients_vals_.resize(num_clients);

        for (int i = 0; i < num_clients; ++i) {
            const auto& client_info_keys = clinets_info_keys[i];
            const auto& client_info_vals = clinets_info_vals[i];

            auto& client_vals = this->clients_vals_[i];
            client_vals.resize(num_total_key);

            for (int j = 0; j < client_info_keys.size(); ++j) {
                std::string_view info_key = client_info_keys[j];
                const auto var_index = this->key_to_var_index_[info_key];

                client_vals[var_index] = client_info_vals[j];
            }
        }
    }

public:
    std::vector<std::vector<std::string>> print(void) const
    {
        std::vector<std::vector<std::string>> result;

        const auto num_clients = this->clients_vals_.size();
        const auto num_key = this->key_to_var_index_.size();

        result.resize(num_clients);

        for (int i = 0; i < num_clients; ++i) {
            result[i].resize(num_key);

            const auto& client_vals = this->clients_vals_[i];
            for (int j = 0; j < num_key; ++j) {
                if (client_vals[j].empty()) {
                    result[i][j] = "-";
                } else {
                    result[i][j] = client_vals[j];
                }
            }
        }

				return result;
    }

private:
    std::map<std::string_view, int> key_to_var_index_;
    std::vector<std::vector<std::string_view>> clients_vals_;
};

std::string solution1(std::string TN, std::vector<std::vector<std::string>> P)
{
    const auto info_key_set = make_infokey_set(P);
    return make_query(TN, info_key_set);
}

std::vector<std::string> solution2(std::string TN, std::vector<std::vector<std::string>> P, std::vector<std::vector<std::string>> V)
{
    const auto clients_keyval_set = make_clients_information_set(P, V);
    return make_insert_query(TN, clients_keyval_set);
}

std::vector<std::vector<std::string>> solution(std::string TN, std::vector<std::vector<std::string>> P, std::vector<std::vector<std::string>> V)
{
    DB db(P, V);

    return db.print();
}