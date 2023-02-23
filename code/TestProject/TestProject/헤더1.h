#pragma once
#include <cctype>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <string_view>
#include <vector>

class OP {
public:
    virtual bool compare(const int sv1, const int sv2) const = 0;
    virtual bool compare(std::string_view sv1, std::string_view sv2) const = 0;
};

class LE : public OP {
public:
    bool compare(std::string_view sv1, std::string_view sv2) const override
    {
        return sv1 <= sv2;
    }
    bool compare(const int sv1, const int sv2) const override
    {
        return sv1 <= sv2;
    }
};

class EQ : public OP {
public:
    bool compare(std::string_view sv1, std::string_view sv2) const override
    {
        return sv1 == sv2;
    }
    bool compare(const int sv1, const int sv2) const override
    {
        return sv1 == sv2;
    }
};

class GE : public OP {
public:
    bool compare(std::string_view sv1, std::string_view sv2) const override
    {
        return sv1 >= sv2;
    }
    bool compare(const int sv1, const int sv2) const override
    {
        return sv1 >= sv2;
    }
};

std::vector<std::string_view> parse(std::string_view sv, std::string_view delimiter)
{
    std::vector<std::string_view> result;

    while (true) {
        auto delimiter_pos = sv.find(delimiter);

        if (delimiter_pos == std::string_view::npos) {
            result.push_back(std::move(sv));
            break;
        }

        auto substr = sv.substr(0, delimiter_pos);

        result.push_back(std::move(substr));

        sv.remove_prefix(delimiter_pos + delimiter.size());
    }

    return result;
}

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
    DB(const std::string& TN, const std::vector<std::vector<std::string>>& clinets_info_keys, const std::vector<std::vector<std::string>>& clinets_info_vals)
    {
        this->table_name_ = TN;

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
            client_vals.resize(num_total_key, "-");

            for (int j = 0; j < client_info_keys.size(); ++j) {
                std::string_view info_key = client_info_keys[j];
                const auto var_index = this->key_to_var_index_[info_key];

                client_vals[var_index] = client_info_vals[j];
            }
        }
    }

public:
    std::vector<std::vector<std::string>> explore_query(std::string_view query) const
    {
        if (query.find(this->table_name_) == std::string_view::npos) {
            return {};
        }

        std::vector<std::vector<std::string>> result;

        auto key_sv = query;

        auto key_start_pos = key_sv.find('(');
        key_sv.remove_prefix(key_start_pos + 1);
        auto key_end_pos = key_sv.find(')');
        key_sv.remove_suffix(key_sv.size() - key_end_pos);

        constexpr auto delimiter = ", ";
        auto keys = parse(key_sv, delimiter);

        auto condition_sv = query;

        auto condition_start_pos = condition_sv.find("where");

        auto has_no_condition = condition_start_pos == std::string_view::npos;

        const auto num_client = this->clients_vals_.size();
        const auto num_key = keys.size();

        if (has_no_condition) {

            result.resize(num_client);
            for (auto& client_infos : result) {
                client_infos.resize(num_key);
            }

            for (int i = 0; i < num_key; ++i) {
                auto key = keys[i];
                auto index = this->key_to_var_index_.at(key);
                for (int j = 0; j < num_client; ++j) {
                    result[j][i] = this->clients_vals_[j][index];
                }
            }
        } else {
            condition_sv.remove_prefix(condition_start_pos + 6);

            constexpr auto space = " ";
            auto parsed_condition = parse(condition_sv, space);

            const auto target_key = parsed_condition[0];
            const auto operation = parsed_condition[1];
            const auto criteria = parsed_condition[2];

            bool is_number = std::isdigit(criteria.front());

            std::unique_ptr<OP> op_ptr;

            if (operation == ">=") {
                op_ptr = std::make_unique<GE>();
            } else if (operation == "==") {
                op_ptr = std::make_unique<EQ>();
            } else {
                op_ptr = std::make_unique<LE>();
            }

            const auto target_index = this->key_to_var_index_.at(target_key);

            std::vector<int> valid_client_index;

            for (int i = 0; i < num_client; ++i) {
                const auto& target_var = this->clients_vals_[i][target_index];

                bool is_valid = false;
                if (is_number) {
                    is_valid = op_ptr->compare(std::stoi(target_var), std::stoi(criteria.data()));
                } else {
                    is_valid = op_ptr->compare(target_var, criteria);
                }

                if (is_valid) {
                    valid_client_index.push_back(i);
                }
            }

            const auto num_valid_client = valid_client_index.size();
            result.resize(num_valid_client);
            for (auto& client_infos : result) {
                client_infos.resize(num_key);
            }

            for (int i = 0; i < num_key; ++i) {
                auto key = keys[i];
                auto var_index = this->key_to_var_index_.at(key);

                for (int j = 0; j < num_valid_client; ++j) {
                    const auto client_index = valid_client_index[j];

                    result[j][i] = this->clients_vals_[client_index][var_index];
                }
            }
        }

        return result;
    }

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
    std::string table_name_;
    std::map<std::string_view, int> key_to_var_index_;
    std::vector<std::vector<std::string>> clients_vals_;
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

std::vector<std::vector<std::string>> solution3(std::string TN, std::vector<std::vector<std::string>> P, std::vector<std::vector<std::string>> V)
{
    DB db(TN, P, V);
    return db.print();
}

std::vector<std::vector<std::string>> solution(std::string TN, std::vector<std::vector<std::string>> P, std::vector<std::vector<std::string>> V, std::string Q)
{
    DB db(TN, P, V);

    return db.explore_query(Q);
}