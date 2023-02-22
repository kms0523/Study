//#include <algorithm>
//#include <optional>
//#include <set>
//#include <stdexcept>
//#include <vector>
//
//enum class day {
//    monday = 1,
//    tuesday,
//    wednesday,
//    thursday,
//    friday,
//    saturday,
//    sunday,
//    num_total_day = 7,
//    not_in_list = -1,
//};
//
//bool contain(const std::vector<int>& sorted_vec, const int val)
//{
//    return std::binary_search(sorted_vec.begin(), sorted_vec.end(), val);
//}
//
//int cal_how_many_days_later(const day start, const day end)
//{
//    const auto start_day_index = static_cast<int>(start);
//    const auto end_day_index = static_cast<int>(end);
//
//    constexpr auto num_total_day = static_cast<int>(day::num_total_day);
//    if (end_day_index < start_day_index) {
//        return end_day_index + num_total_day - start_day_index;
//    } else {
//        return end_day_index - start_day_index;
//    }
//}
//
//day cal_next_day(const day start, const int num_days)
//{
//    const auto start_day_index = static_cast<int>(start);
//    auto result_index = start_day_index + num_days;
//
//    constexpr auto sunday_index = static_cast<int>(day::sunday);
//    if (sunday_index < result_index) {
//        result_index -= sunday_index;
//    }
//
//    return static_cast<day>(result_index);
//}
//
//int num_days_in_month(const int month_index)
//{
//    switch (month_index) {
//    case 1:
//    case 3:
//    case 5:
//    case 7:
//    case 8:
//    case 10:
//    case 12:
//        return 31;
//    case 2:
//        return 28;
//    default:
//        return 30;
//        break;
//    }
//}
//
//bool is_weekends(const day d)
//{
//    return d == day::saturday || d == day::sunday;
//}
//
//class Date {
//public:
//    Date(void) = default;
//    Date(const int month, const int day)
//        : month_(month)
//        , day_(day){};
//
//    // command
//public:
//    void next(const int num_day = 1)
//    {
//        this->day_ += num_day;
//
//        const auto this_month_last_day = num_days_in_month(this->month_);
//        if (this_month_last_day < this->day_) {
//            this->month_++;
//            this->day_ -= this_month_last_day;
//        }
//
//        constexpr auto max_month = 12;
//        if (max_month < this->month_) {
//            throw std::runtime_error("next year exception");
//        }
//    }
//
//    void previous(const int num_day = 1)
//    {
//        this->day_ -= num_day;
//
//        if (this->day_ < 1) {
//            this->month_--;
//
//            const auto this_month_last_day = num_days_in_month(this->month_);
//            const auto num_backward = 1 - this->day_;
//            this->day_ = this_month_last_day - num_backward;
//        }
//
//        constexpr auto min_month = 1;
//        if (this->month_ < min_month) {
//            throw std::runtime_error("last year exception");
//        }
//    }
//
//    // query
//public:
//    operator std::pair<int, int>(void) const
//    {
//        return { this->month_, this->day_ };
//    }
//
//    int operator-(const Date& other) const
//    {
//        if (this->month_ == other.month_) {
//            return this->day_ - other.day_;
//        } else if (this->month_ < other.month_) {
//            auto day = other.day_;
//            auto month = other.month_;
//
//            auto result = 1 - other.day_;
//
//            while (true) {
//                if (month == this->month_) {
//                    result += this->day_ - 1;
//                    return result;
//                }
//
//                month--;
//                const auto last_day = num_days_in_month(month);
//                result -= last_day;
//            }
//        } else {
//            auto day = other.day_;
//            auto month = other.month_;
//
//            const auto last_day = num_days_in_month(month);
//            auto result = last_day - day;
//            month++;
//
//            while (true) {
//                if (month == this->month_) {
//                    result += this->day_;
//                    return result;
//                }
//
//                const auto last_day = num_days_in_month(month);
//                result += last_day;
//                month++;
//            }
//        }
//    }
//
//    bool operator<(const Date& other) const
//    {
//        if (this->month_ == other.month_) {
//            return this->day_ < other.day_;
//        } else {
//            return this->month_ < other.month_;
//        }
//    }
//
//    bool operator<=(const Date& other) const
//    {
//        if (this->month_ == other.month_) {
//            return this->day_ <= other.day_;
//        } else {
//            return this->month_ <= other.month_;
//        }
//    }
//
//    bool operator==(const Date& other) const
//    {
//        return this->month_ == other.month_ && this->day_ == other.day_;
//    }
//
//public:
//    Date get_next(const int num_day = 1) const
//    {
//        auto result = *this;
//        result.next(num_day);
//        return result;
//    }
//
//    Date get_previous(const int num_day = 1) const
//    {
//        auto result = *this;
//        result.previous(num_day);
//        return result;
//    }
//    int month(void) const { return this->month_; };
//    int day(void) const { return this->day_; };
//
//private:
//    int month_ = 1;
//    int day_ = 1;
//};
//
//bool contain(const std::set<Date>& set, const Date val)
//{
//    return set.find(val) != set.end();
//}
//
//class Consecutive_Dates {
//public:
//    Consecutive_Dates(const Date begin_date, const Date end_date)
//        : begin_date_(begin_date)
//        , end_date_(end_date)
//    {
//        if (this->end_date_ < this->begin_date_) {
//            throw std::invalid_argument("invalid input");
//        }
//    }
//
//    // command
//public:
//    void extend_end_date(void)
//    {
//        this->end_date_.next();
//    }
//    void extend_begin_date(void)
//    {
//        this->begin_date_.previous();
//    }
//    void try_merge(const Consecutive_Dates& other)
//    {
//        if (this->begin_date_.get_previous() == other.end_date_) {
//            this->begin_date_ = other.begin_date_;
//        } else if (this->end_date_.get_next() == other.begin_date_) {
//            this->end_date_ = other.end_date_;
//        }
//    }
//
//    // query
//public:
//    const Date& begin_date(void) const
//    {
//        return this->begin_date_;
//    }
//    const Date& end_date(void) const
//    {
//        return this->end_date_;
//    }
//    int num_day(void) const
//    {
//        return (this->end_date_ - this->begin_date_) + 1;
//    }
//
//private:
//    Date begin_date_;
//    Date end_date_;
//};
//
//using CDates = Consecutive_Dates;
//
//class Calender {
//
//public:
//    Calender(const day year_start_day, const std::set<Date>& holiday_date_set)
//    {
//        this->break_date_set_ = holiday_date_set;
//
//        Date date;
//
//        auto current_day = year_start_day;
//        if (current_day == day::sunday) {
//            this->insert_sunday_as_break_day(this->break_date_set_, date);
//        }
//
//        while (true) {
//            const auto num_days_from_saturday = cal_how_many_days_later(current_day, day::saturday);
//
//            try {
//                date.next(num_days_from_saturday);
//                insert_saturday_as_break_day(this->break_date_set_, date);
//
//                date.next();
//                insert_sunday_as_break_day(this->break_date_set_, date);
//            } catch (...) {
//                // till next year exception occur
//                break;
//            }
//
//            current_day = day::sunday;
//        }
//    }
//
//public:
//    std::vector<int> cal_best_vacation_plan(const int num_vacation) const
//    {
//        const auto cdatess = this->make_consecutive_dates();
//        const auto best_vacation_plan_candidates = this->cal_best_vacation_plan_candidates(cdatess, num_vacation);
//
//        int best_plan_index = 0;
//        int max_days = 0;
//
//        const auto num_candidates = best_vacation_plan_candidates.size();
//        for (int i = 0; i < num_candidates; ++i) {
//            const auto& candidate = best_vacation_plan_candidates[i];
//            const auto num_days = candidate.num_day();
//
//            if (max_days < num_days) {
//                max_days = num_days;
//                best_plan_index = i;
//            }
//        }
//
//        const auto& best_plan = best_vacation_plan_candidates[best_plan_index];
//
//        const auto best_num_days = best_plan.num_day();
//        const auto best_begin_month = best_plan.begin_date().month();
//        const auto best_begin_day = best_plan.begin_date().day();
//        const auto best_end_month = best_plan.end_date().month();
//        const auto best_end_day = best_plan.end_date().day();
//
//        return { best_num_days, best_begin_month, best_begin_day, best_end_month, best_end_day };
//    }
//
//    int cal_num_break_day(void) const
//    {
//        return static_cast<int>(this->break_date_set_.size());
//    }
//
//    std::vector<int> cal_pay_days(const int standard_pay_day) const
//    {
//        auto month_to_break_days = this->make_month_to_break_day();
//
//        constexpr auto num_month = 12;
//        std::vector<int> pay_days(num_month);
//
//        for (int i = 0; i < num_month; ++i) {
//            const auto month = i + 1;
//            const auto& break_days = month_to_break_days[month];
//
//            if (!contain(break_days, standard_pay_day)) {
//                pay_days[i] = standard_pay_day;
//                continue;
//
//            } else {
//                bool last_month_flag = false;
//                bool next_month_flag = false;
//
//                const auto current_month_last_day = num_days_in_month(month);
//
//                int jump_index = 1;
//                while (true) {
//                    if (standard_pay_day <= jump_index) {
//                        last_month_flag = true;
//                    }
//
//                    if (current_month_last_day < standard_pay_day + jump_index) {
//                        next_month_flag = true;
//                    }
//
//                    if (last_month_flag && next_month_flag) {
//                        pay_days[i] = standard_pay_day;
//                        break;
//                    }
//
//                    if (!last_month_flag) {
//                        auto new_pay_day1 = standard_pay_day - jump_index;
//
//                        if (!contain(break_days, new_pay_day1)) {
//                            pay_days[i] = new_pay_day1;
//                            break;
//                        }
//                    }
//
//                    if (!next_month_flag) {
//                        auto new_pay_day2 = standard_pay_day + jump_index;
//
//                        if (!contain(break_days, new_pay_day2)) {
//                            pay_days[i] = new_pay_day2;
//                            break;
//                        }
//                    }
//
//                    jump_index++;
//                }
//            }
//        }
//
//        return pay_days;
//    }
//
//private:
//    std::vector<Consecutive_Dates> cal_best_vacation_plan_candidates(const std::vector<Consecutive_Dates>& cdatess, const int num_vacation) const
//    {
//        const auto num_cdates = cdatess.size();
//        std::vector<CDates> best_vacation_candidates;
//        best_vacation_candidates.reserve(num_cdates);
//
//        for (int i = 0; i < num_cdates; ++i) {
//            const auto& start_cdates = cdatess[i];
//
//            bool last_year_exception_not_occur = true;
//            bool next_year_exception_not_occur = true;
//            CDates result = start_cdates;
//
//            for (int j = 0; j < num_vacation; ++j) {
//                const auto [opt_before_cdates, opt_after_cdates] = this->find_right_before_and_after(cdatess, result);
//
//                auto candidate1 = result;
//
//                if (last_year_exception_not_occur) {
//                    try {
//                        candidate1.extend_begin_date();
//
//                        if (opt_before_cdates.has_value()) {
//                            candidate1.try_merge(opt_before_cdates.value());
//                        }
//
//                    } catch (...) {
//                        candidate1 = result;
//                        last_year_exception_not_occur = false;
//                    }
//                }
//
//                auto candidate2 = result;
//
//                if (next_year_exception_not_occur) {
//                    try {
//                        candidate2.extend_end_date();
//
//                        if (opt_after_cdates.has_value()) {
//                            candidate2.try_merge(opt_after_cdates.value());
//                        }
//
//                    } catch (...) {
//                        candidate2 = result;
//                        next_year_exception_not_occur = false;
//                    }
//                }
//
//                if (candidate1.num_day() < candidate2.num_day()) {
//                    result = candidate2;
//                } else {
//                    result = candidate1;
//                }
//            }
//
//            best_vacation_candidates.push_back(result);
//        }
//
//        return best_vacation_candidates;
//    }
//
//    std::pair<std::optional<CDates>, std::optional<CDates>> find_right_before_and_after(const std::vector<CDates>& cdatess, const CDates& target) const
//    {
//        std::pair<std::optional<CDates>, std::optional<CDates>> result;
//
//        bool exist_right_back = true;
//        bool exist_right_after = true;
//
//        auto index = 0;
//
//        if (target.begin_date() < cdatess.front().end_date()) {
//            exist_right_back = false;
//            index++;
//        }
//
//        if (cdatess.back().begin_date() < target.end_date()) {
//            exist_right_after = false;
//        }
//
//        if (exist_right_back) {
//            while (true) {
//                if (cdatess[index].end_date() < target.begin_date() && target.begin_date() <= cdatess[index + 1].end_date()) {
//                    result.first = cdatess[index];
//                    index++;
//                    break;
//                } else {
//                    index++;
//                }
//            }
//        }
//
//        if (exist_right_after) {
//            while (true) {
//                if (cdatess[index - 1].begin_date() <= target.end_date() && target.end_date() < cdatess[index].begin_date()) {
//                    result.second = cdatess[index];
//                    break;
//                } else {
//                    index++;
//                }
//            }
//        }
//
//        return result;
//    }
//
//    std::vector<Consecutive_Dates> make_consecutive_dates(void) const
//    {
//        std::vector<Consecutive_Dates> result;
//
//        auto begin_iter = this->break_date_set_.begin();
//        auto end_iter = begin_iter;
//
//        while (true) {
//            auto iter = std::next(end_iter);
//
//            while (true) {
//                if (end_iter->get_next() == *iter) {
//                    iter++;
//                    end_iter++;
//
//                    if (iter == this->break_date_set_.end()) {
//                        auto cd = Consecutive_Dates(*begin_iter, *end_iter);
//                        result.push_back(cd);
//                        return result;
//                    }
//
//                } else {
//                    auto cd = Consecutive_Dates(*begin_iter, *end_iter);
//                    result.push_back(cd);
//                    break;
//                }
//            }
//
//            begin_iter = std::next(end_iter);
//            end_iter = begin_iter;
//        }
//
//    }
//
//    std::vector<std::vector<int>> make_month_to_break_day(void) const
//    {
//        constexpr auto num_month = 12;
//        std::vector<std::vector<int>> month_to_break_days(num_month + 1);
//
//        constexpr auto num_max_break_days_per_month = 15;
//        for (auto& break_days : month_to_break_days) {
//            break_days.reserve(num_max_break_days_per_month);
//        }
//
//        for (const auto& date : this->break_date_set_) {
//            month_to_break_days[date.month()].push_back(date.day());
//        }
//
//        return month_to_break_days;
//    }
//
//    void consider_temporary_holiday_begin_with_saturday(std::set<Date>& break_date_set, const Date current_date) const
//    {
//        auto temporary_holiday_date = current_date;
//
//        while (true) {
//            try {
//                temporary_holiday_date.previous(1);
//            } catch (...) {
//                // last year exception will be ignored
//                return;
//            }
//
//            auto [iter, success_insertion] = break_date_set.insert(temporary_holiday_date);
//
//            if (success_insertion) {
//                return;
//            }
//        }
//    }
//
//    void consider_temporary_holiday_begin_with_sunday(std::set<Date>& break_date_set, const Date current_date) const
//    {
//        auto temporary_holiday_date = current_date;
//
//        while (true) {
//            try {
//                temporary_holiday_date.next(1);
//            } catch (...) {
//                // next year exception will be ignored
//                return;
//            }
//
//            auto [iter, success_insertion] = break_date_set.insert(temporary_holiday_date);
//
//            if (success_insertion) {
//                return;
//            }
//        }
//    }
//
//    void insert_saturday_as_break_day(std::set<Date>& break_date_set, const Date current_date) const
//    {
//        auto [iter, success_insertion] = break_date_set.insert(current_date);
//
//        bool saturday_is_holiday = !success_insertion;
//        if (saturday_is_holiday) {
//            consider_temporary_holiday_begin_with_saturday(break_date_set, current_date);
//        }
//    }
//
//    void insert_sunday_as_break_day(std::set<Date>& break_date_set, const Date current_date) const
//    {
//        auto [iter, success_insertion] = break_date_set.insert(current_date);
//
//        bool sunday_is_holiday = !success_insertion;
//        if (sunday_is_holiday) {
//            consider_temporary_holiday_begin_with_sunday(break_date_set, current_date);
//        }
//    }
//
//private:
//    std::set<Date> break_date_set_;
//};
//
//#include <iostream>
//std::vector<int> solution(int X, std::vector<std::vector<int>> H, int N)
//{
//    std::set<Date> holiday_date_set;
//
//    for (const auto vec : H) {
//        const auto month = vec[0];
//        const auto date = vec[1];
//        holiday_date_set.insert({ month, date });
//    }
//
//    day year_start_day = static_cast<day>(X);
//
//    Calender calender(year_start_day, holiday_date_set);
//
//		std::cout << calender.cal_num_break_day() << "\n";
//		//return calender.cal_num_break_day();
//		return calender.cal_best_vacation_plan(N);
//}