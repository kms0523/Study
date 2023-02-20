//#include <algorithm>
//#include <set>
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
//bool contain(const std::set<int>& set, const int val)
//{
//    return set.find(val) != set.end();
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
//int last_day_in_month(const int month_index)
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
//
//public:
//    Date(void) = default;
//    Date(const int month, const int day)
//        : month_(month)
//        , day_(day){};
//
//    //command
//public:
//    void next(const int num_day)
//    {
//        this->day_ += num_day;
//
//        const auto this_month_last_day = last_day_in_month(this->month_);
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
//    void previous(const int num_day)
//    {
//        this->day_ -= num_day;
//
//        if (this->day_ < 1) {
//            this->month_--;
//
//            const auto this_month_last_day = last_day_in_month(this->month_);
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
//    //Date next(const int num_day) const
//    //{
//    //    auto result_month = this->month_;
//    //    auto result_day = this->day_ + num_day;
//
//    //    const auto this_month_last_day = last_day_in_month(this->month_);
//    //    if (this_month_last_day < result_day) {
//    //        result_month++;
//    //        result_day -= this_month_last_day;
//    //    }
//
//    //    constexpr auto max_month = 12;
//    //    if (max_month < result_month) {
//    //        throw std::runtime_error("next year exception");
//    //    }
//
//    //    return { result_month, result_day };
//    //}
//
//    //Date get_previous_date(const int num_day) const
//    //{
//    //    auto result_month = this->month_;
//    //    auto result_day = this->day_ - num_day;
//
//    //    if (result_day < 1) {
//    //        result_month--;
//
//    //        const auto result_month_last_day = last_day_in_month(result_month);
//    //        const auto num_backward = 1 - result_day;
//    //        result_day = result_month_last_day - num_backward;
//    //    }
//
//    //constexpr auto min_month = 12;
//    //if (min_month < this->month_) {
//    //        throw std::runtime_error("last year exception");
//    //    }
//
//    //    return { result_month, result_day };
//    //}
//
//public:
//    operator std::pair<int, int>(void) const
//    {
//        return { this->month_, this->day_ };
//    }
//
//private:
//    int month_ = 1;
//    int day_ = 1;
//};
//
//void consider_temporary_holiday_begin_with_saturday(std::set<std::pair<int, int>>& break_date_set, const Date current_date)
//{
//    auto temporary_holiday_date = current_date;
//
//    while (true) {
//        try {
//            temporary_holiday_date.previous(1);
//        } catch (...) {
//            // last year exception will be ignored
//            return;
//        }
//
//        auto [iter, success_insertion] = break_date_set.insert(temporary_holiday_date);
//
//        if (success_insertion) {
//            return;
//        }
//    }
//}
//
//void consider_temporary_holiday_begin_with_sunday(std::set<std::pair<int, int>>& break_date_set, const Date current_date)
//{
//    auto temporary_holiday_date = current_date;
//
//    while (true) {
//        try {
//            temporary_holiday_date.next(1);
//        } catch (...) {
//            // next year exception will be ignored
//            return;
//        }
//
//        auto [iter, success_insertion] = break_date_set.insert(temporary_holiday_date);
//
//        if (success_insertion) {
//            return;
//        }
//    }
//}
//
//int solution(int X, std::vector<std::vector<int>> H)
//{
//    std::set<std::pair<int, int>> break_date_set;
//
//    for (const auto vec : H) {
//        const auto month = vec[0];
//        const auto date = vec[1];
//        break_date_set.insert({ month, date });
//    }
//
//    Date date;
//
//    day current_day = static_cast<day>(X);
//    if (current_day == day::sunday) {
//        break_date_set.insert(date);
//        date.next(1);
//        current_day = day::monday;
//    }
//
//    while (true) {
//        const auto num_days_from_saturday = cal_how_many_days_later(current_day, day::saturday);
//
//        try {
//            date.next(num_days_from_saturday);
//            auto [iter, success_insertion] = break_date_set.insert(date);
//
//            bool saturday_is_holiday = !success_insertion;
//            if (saturday_is_holiday) {
//                consider_temporary_holiday_begin_with_saturday(break_date_set, date);
//            }
//
//            date.next(1);
//            auto [iter2, success_insertion2] = break_date_set.insert(date);
//
//            bool sunday_is_holiday = !success_insertion2;
//            if (sunday_is_holiday) {
//                consider_temporary_holiday_begin_with_sunday(break_date_set, date);
//            }
//        } catch (...) {
//            //till next year exception occur
//            break;
//        }
//
//        current_day = day::sunday;
//    }
//
//    return static_cast<int>(break_date_set.size());
//}
//
//#include <iostream>
//
//int main(void)
//{
//    std::cout << solution(7, std::vector<std::vector<int>>());
//}
//
////        const auto days_later = cal_how_many_days_later(current_day, day::saturday);
////        date += days_later;
////
////        constexpr auto num_day_per_week = 7;
////        while (true) {
////            this->insert_saturday(break_dates, date);
////            this->insert_sunday(break_dates, date + 1);
////
////            const auto next_saturday_date = date + num_day_per_week;
////
////            if (next_saturday_date < this->last_date_) {
////                date = next_saturday_date;
////
////            } else if (next_saturday_date == this->last_date_) {
////                date = this->last_date_;
////                this->insert_saturday(break_dates, date);
////                break;
////
////            } else {
////                break;
////            }
////        }
////
////        return static_cast<int>(break_dates.size());
//
////
////
////class Month {
////
////public:
////    Month(const day start_day, const int num_day)
////        : start_day_(start_day)
////        , last_date_(num_day){};
////
////public:
////    int cal_num_break_day(const std::vector<int>& holiday_dates)
////    {
////        constexpr auto expected_max_num_break_days = 15;
////        std::set<int> break_dates(holiday_dates.begin(), holiday_dates.end());
////
////        int date = 1;
////        day current_day = this->start_day_;
////
////        if (current_day == day::sunday) {
////            break_dates.insert(date);
////            date++;
////            current_day = day::monday;
////        }
////
////        const auto days_later = cal_how_many_days_later(current_day, day::saturday);
////        date += days_later;
////
////        constexpr auto num_day_per_week = 7;
////        while (true) {
////            this->insert_saturday(break_dates, date);
////            this->insert_sunday(break_dates, date + 1);
////
////            const auto next_saturday_date = date + num_day_per_week;
////
////            if (next_saturday_date < this->last_date_) {
////                date = next_saturday_date;
////
////            } else if (next_saturday_date == this->last_date_) {
////                date = this->last_date_;
////                this->insert_saturday(break_dates, date);
////                break;
////
////            } else {
////                break;
////            }
////        }
////
////        return static_cast<int>(break_dates.size());
////    }
////
////public:
////    day cal_last_day(void) const
////    {
////        return this->cal_day(this->last_date_);
////    }
////
////private:
////    day cal_day(int date) const
////    {
////        const auto num_rest_days = date - 1;
////
////        constexpr auto num_day_per_week = 7;
////        const auto num_rest_days_in_last_week = num_rest_days % num_day_per_week;
////
////        return cal_next_day(this->start_day_, num_rest_days_in_last_week);
////    }
////
////    void insert_saturday(std::set<int>& break_dates, const int current_date)
////    {
////        auto [iter, success_insertion] = break_dates.insert(current_date);
////
////        bool saturday_is_holiday = !success_insertion;
////        if (saturday_is_holiday) {
////            this->consider_temporary_holiday_begin_with_saturday(break_dates, current_date);
////        }
////    }
////
////    void insert_sunday(std::set<int>& break_dates, const int current_date)
////    {
////        auto [iter, success_insertion] = break_dates.insert(current_date);
////
////        bool sunday_is_holiday = !success_insertion;
////        if (sunday_is_holiday) {
////            this->consider_temporary_holiday_begin_with_sunday(break_dates, current_date);
////        }
////    }
////
//
////
////    void consider_temporary_holiday_begin_with_sunday(std::set<int>& break_dates, const int current_date)
////    {
////        auto temporary_holiday_date = current_date;
////
////        while (true) {
////            temporary_holiday_date++;
////            auto [iter, success_insertion] = break_dates.insert(temporary_holiday_date);
////
////            if (success_insertion) {
////                break;
////            }
////            if (this->last_date_ < temporary_holiday_date) {
////                this->num_temporary_holdays_to_go_to_next_month++;
////                break;
////            }
////        }
////    }
////
////private:
////    int last_date_ = 0;
////    day start_day_ = day::not_in_list;
////    int num_temporary_holdays_to_go_to_last_month = 0;
////    int num_temporary_holdays_to_go_to_next_month = 0;
////};
////
////int solution(int X, std::vector<std::vector<int>> H)
////{
////    constexpr auto num_month = 12;
////    std::vector<std::vector<int>> month_to_holidays(num_month + 1);
////
////    for (const auto vec : H) {
////        const auto month = vec[0];
////        const auto date = vec[1];
////        month_to_holidays[month].push_back(date);
////    }
////
////    auto num_break_days = 0;
////
////    day start_day = static_cast<day>(X);
////
////    for (int i = 1; i <= num_month; ++i) {
////        const auto num_days = last_day_in_month(i);
////        Month current_month(start_day, num_days);
////
////        const auto& holidays = month_to_holidays[i];
////        num_break_days += current_month.cal_num_break_day(holidays);
////        start_day = cal_next_day(current_month.cal_last_day(), 1);
////    }
////
////
////
////    return num_break_days;
////}
////
