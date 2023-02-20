#include <algorithm>
#include <set>
#include <vector>

enum class day {
    monday = 1,
    tuesday,
    wednesday,
    thursday,
    friday,
    saturday,
    sunday,
    num_total_day = 7,
    not_in_list = -1,
};

class Date;

bool contain(const std::set<Date>& set, const Date val)
{
    return set.find(val) != set.end();
}

bool contain(const std::vector<int>& sorted_vec, const int val)
{
    return std::binary_search(sorted_vec.begin(), sorted_vec.end(), val);
}

int cal_how_many_days_later(const day start, const day end)
{
    const auto start_day_index = static_cast<int>(start);
    const auto end_day_index = static_cast<int>(end);

    constexpr auto num_total_day = static_cast<int>(day::num_total_day);
    if (end_day_index < start_day_index) {
        return end_day_index + num_total_day - start_day_index;
    } else {
        return end_day_index - start_day_index;
    }
}

day cal_next_day(const day start, const int num_days)
{
    const auto start_day_index = static_cast<int>(start);
    auto result_index = start_day_index + num_days;

    constexpr auto sunday_index = static_cast<int>(day::sunday);
    if (sunday_index < result_index) {
        result_index -= sunday_index;
    }

    return static_cast<day>(result_index);
}

int last_day_in_month(const int month_index)
{
    switch (month_index) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    case 2:
        return 28;
    default:
        return 30;
        break;
    }
}

bool is_weekends(const day d)
{
    return d == day::saturday || d == day::sunday;
}

class Date {

public:
    Date(void) = default;
    Date(const int month, const int day)
        : month_(month)
        , day_(day){};

    //command
public:
    void next(const int num_day = 1)
    {
        this->day_ += num_day;

        const auto this_month_last_day = last_day_in_month(this->month_);
        if (this_month_last_day < this->day_) {
            this->month_++;
            this->day_ -= this_month_last_day;
        }

        constexpr auto max_month = 12;
        if (max_month < this->month_) {
            throw std::runtime_error("next year exception");
        }
    }

    void previous(const int num_day)
    {
        this->day_ -= num_day;

        if (this->day_ < 1) {
            this->month_--;

            const auto this_month_last_day = last_day_in_month(this->month_);
            const auto num_backward = 1 - this->day_;
            this->day_ = this_month_last_day - num_backward;
        }

        constexpr auto min_month = 1;
        if (this->month_ < min_month) {
            throw std::runtime_error("last year exception");
        }
    }

    //query
public:
    operator std::pair<int, int>(void) const
    {
        return { this->month_, this->day_ };
    }

    bool operator<(const Date& other) const
    {
        if (this->month_ == other.month_) {
            return this->day_ < other.day_;
        } else {
            return this->month_ < other.month_;
        }
    }

public:
    Date get_next(const int num_day = 1) const
    {
        auto result = *this;
        result.next(num_day);
        return result;
    }

    Date get_previous(const int num_day = 1) const
    {
        auto result = *this;
        result.previous(num_day);
        return result;
    }
    int month(void) const { return this->month_; };
    int day(void) const { return this->day_; };

private:
    int month_ = 1;
    int day_ = 1;
};

class Calender {

public:
    Calender(const day year_start_day, const std::set<Date>& holiday_date_set)
    {
        this->break_date_set_ = holiday_date_set;

        Date date;

        auto current_day = year_start_day;
        if (current_day == day::sunday) {
            this->insert_sunday_as_break_day(this->break_date_set_, date);
        }

        while (true) {
            const auto num_days_from_saturday = cal_how_many_days_later(current_day, day::saturday);

            try {
                date.next(num_days_from_saturday);
                insert_saturday_as_break_day(this->break_date_set_, date);

                date.next();
                insert_sunday_as_break_day(this->break_date_set_, date);
            } catch (...) {
                //till next year exception occur
                break;
            }

            current_day = day::sunday;
        }
    }

public:
    std::vector<int> cal_best_vacation_plan(const int num_vacation) const
    {
        for (const auto& search_start_date : this->break_date_set_) {

            auto next_date = search_start_date.get_next();
            auto previous_date = search_start_date.get_previous();

            if (contain(this->break_date_set_, next_date) && contain(this->break_date_set_, previous_date)) {
                continue;
            }
        }
    }

    int cal_num_break_day(void) const
    {
        return static_cast<int>(this->break_date_set_.size());
    }

    std::vector<int> cal_pay_days(const int standard_pay_day) const
    {
        auto month_to_break_days = this->make_month_to_break_day();

        constexpr auto num_month = 12;
        std::vector<int> pay_days(num_month);

        for (int i = 0; i < num_month; ++i) {
            const auto month = i + 1;
            const auto& break_days = month_to_break_days[month];

            if (!contain(break_days, standard_pay_day)) {
                pay_days[i] = standard_pay_day;
                continue;

            } else {
                bool last_month_flag = false;
                bool next_month_flag = false;

                const auto current_month_last_day = last_day_in_month(month);

                int jump_index = 1;
                while (true) {
                    if (standard_pay_day <= jump_index) {
                        last_month_flag = true;
                    }

                    if (current_month_last_day < standard_pay_day + jump_index) {
                        next_month_flag = true;
                    }

                    if (last_month_flag && next_month_flag) {
                        pay_days[i] = standard_pay_day;
                        break;
                    }

                    if (!last_month_flag) {
                        auto new_pay_day1 = standard_pay_day - jump_index;

                        if (!contain(break_days, new_pay_day1)) {
                            pay_days[i] = new_pay_day1;
                            break;
                        }
                    }

                    if (!next_month_flag) {
                        auto new_pay_day2 = standard_pay_day + jump_index;

                        if (!contain(break_days, new_pay_day2)) {
                            pay_days[i] = new_pay_day2;
                            break;
                        }
                    }

                    jump_index++;
                }
            }
        }

        return pay_days;
    }

private:
    std::vector<int> search_vacation_plan(const Date& date, const int num_vacation) const
    {


    }

    std::vector<std::vector<int>> make_month_to_break_day(void) const
    {
        constexpr auto num_month = 12;
        std::vector<std::vector<int>> month_to_break_days(num_month + 1);

        constexpr auto num_max_break_days_per_month = 15;
        for (auto& break_days : month_to_break_days) {
            break_days.reserve(num_max_break_days_per_month);
        }

        for (const auto& date : this->break_date_set_) {
            month_to_break_days[date.month()].push_back(date.day());
        }

        return month_to_break_days;
    }

    void consider_temporary_holiday_begin_with_saturday(std::set<Date>& break_date_set, const Date current_date) const
    {
        auto temporary_holiday_date = current_date;

        while (true) {
            try {
                temporary_holiday_date.previous(1);
            } catch (...) {
                // last year exception will be ignored
                return;
            }

            auto [iter, success_insertion] = break_date_set.insert(temporary_holiday_date);

            if (success_insertion) {
                return;
            }
        }
    }

    void consider_temporary_holiday_begin_with_sunday(std::set<Date>& break_date_set, const Date current_date) const
    {
        auto temporary_holiday_date = current_date;

        while (true) {
            try {
                temporary_holiday_date.next(1);
            } catch (...) {
                // next year exception will be ignored
                return;
            }

            auto [iter, success_insertion] = break_date_set.insert(temporary_holiday_date);

            if (success_insertion) {
                return;
            }
        }
    }

    void insert_saturday_as_break_day(std::set<Date>& break_date_set, const Date current_date) const
    {
        auto [iter, success_insertion] = break_date_set.insert(current_date);

        bool saturday_is_holiday = !success_insertion;
        if (saturday_is_holiday) {
            consider_temporary_holiday_begin_with_saturday(break_date_set, current_date);
        }
    }

    void insert_sunday_as_break_day(std::set<Date>& break_date_set, const Date current_date) const
    {
        auto [iter, success_insertion] = break_date_set.insert(current_date);

        bool sunday_is_holiday = !success_insertion;
        if (sunday_is_holiday) {
            consider_temporary_holiday_begin_with_sunday(break_date_set, current_date);
        }
    }

private:
    std::set<Date> break_date_set_;
};

std::vector<int> solution(int X, std::vector<std::vector<int>> H, int Y)
{
    std::set<Date> holiday_date_set;

    for (const auto vec : H) {
        const auto month = vec[0];
        const auto date = vec[1];
        holiday_date_set.insert({ month, date });
    }

    day year_start_day = static_cast<day>(X);

    Calender calender(year_start_day, holiday_date_set);
    return calender.cal_pay_days(Y);
}

#include <iostream>

int main(void)
{
    auto result = solution(7, std::vector<std::vector<int>>(), 1);

    for (const auto e : result)
        std::cout << e << "\n";
}
