#pragma once
#include <array>
#include <optional>
#include <vector>

enum class Day_Type {
	work_day,
	saturday,
	sunday,
	holiday,
};

int num_days_in_month(const int month_index)
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

class Calender
{
public:
	Calender(const int start_day_index, const std::vector<std::vector<int>>& holiday_dates)
	{
		this->set_month_to_date_index();
		this->set_weekends(start_day_index);
		this->set_holiday(holiday_dates);
	}

public:
	int cal_num_break_day(void) const
	{
		auto num_break_day = Calender::num_day_in_year;

		for (const auto& type : this->date_index_to_day_type_) {
			if (type == Day_Type::work_day) {
				num_break_day--;
			}
		}

		return num_break_day;
	}

	std::vector<int> cal_best_vacation_plan(const int num_vacation) const
	{
		constexpr auto start_date_index = 0;

		auto date_index = 0;
		if (this->date_index_to_day_type_[start_date_index] == Day_Type::work_day) {
			date_index = this->find_next_longweekend_date_index(start_date_index).value();
		}

		std::vector<std::pair<int, int>> best_vacation_plan_candidates;

		while (true) {
			best_vacation_plan_candidates.push_back(this->find_vacation_plan(date_index, num_vacation));

			auto opt_next_longweekend_date_index = this->find_next_longweekend_date_index(date_index);

			if (opt_next_longweekend_date_index.has_value()) {
				date_index = opt_next_longweekend_date_index.value();
			}
			else {
				break;
			}
		}

		int max = 0;
		int best_begin_date_index = 0;
		int best_end_date_index = 0;

		for (auto [begin_date_index, end_date_index] : best_vacation_plan_candidates) {
			auto num_day = end_date_index - begin_date_index + 1;

			if (max < num_day) {
				max = num_day;
				best_begin_date_index = begin_date_index;
				best_end_date_index = end_date_index;
			}
		}

		auto [bmonth, bday] = this->to_month_day(best_begin_date_index);
		auto [emonth, eday] = this->to_month_day(best_end_date_index);

		return { max, bmonth, bday, emonth, eday };
	}

private:
	std::pair<int, int> find_vacation_plan(const int breakday_date_index, const int num_vacation) const
	{
		auto num_used_vacation = 0;

		auto vacation_begin_date_index = breakday_date_index;
		auto vacation_end_date_index = breakday_date_index;

		bool is_last_year = false;

		while (true) {
			auto opt_date_index = this->find_right_before_work_day_date_index(vacation_begin_date_index);

			if (opt_date_index.has_value()) {
				vacation_begin_date_index = opt_date_index.value();
				num_used_vacation++;

				if (num_used_vacation == num_vacation) {
					break;
				}
			}
			else {
				is_last_year = true;
				break;
			}
		}

		if (is_last_year) {
			while (true) {
				auto opt_date_index = this->find_right_after_work_day_date_index(vacation_end_date_index);

				if (opt_date_index.has_value()) {
					vacation_end_date_index = opt_date_index.value();
					num_used_vacation++;

					if (num_used_vacation == num_vacation) {
						break;
					}
				}
				else {
					throw std::runtime_error("next year exception");
				}
			}
		}

		auto opt_workday_date_index1 = this->find_right_before_work_day_date_index(vacation_begin_date_index);
		if (opt_workday_date_index1.has_value()) {
			const auto workday_date_index1 = opt_workday_date_index1.value();

			if (workday_date_index1 != vacation_begin_date_index - 1) {
				vacation_begin_date_index = workday_date_index1 + 1;
			}
		}
		else {
			vacation_begin_date_index = 0;
		}

		auto opt_temp_date_index2 = this->find_right_after_work_day_date_index(vacation_end_date_index);
		if (opt_temp_date_index2.has_value()) {
			const auto temp_date_index2 = opt_temp_date_index2.value();

			if (temp_date_index2 != vacation_end_date_index + 1) {
				vacation_end_date_index = temp_date_index2 - 1;
			}
		}
		else {
			vacation_end_date_index = 364;
		}

		return { vacation_begin_date_index, vacation_end_date_index };
	}

	void set_month_to_date_index(void)
	{
		auto date_index = 0;
		for (int month = 1; month <= Calender::num_month_in_year; ++month) {
			const auto month_index = this->cal_month_index(month);
			this->month_index_to_date_index_[month_index] = date_index;
			date_index += num_days_in_month(month);
		}
	}

	void set_weekends(const int start_day_index)
	{
		auto first_saturday_day = 7 - start_day_index;

		if (first_saturday_day == 0) {
			this->date_index_to_day_type_[0] = Day_Type::sunday;
			first_saturday_day = 7;
		}

		const auto first_saturday_date_index = this->cal_date_index(1, first_saturday_day);
		auto saturday_date_index = first_saturday_date_index;

		constexpr auto last_date_index = 364;

		while (true) {
			this->date_index_to_day_type_[saturday_date_index] = Day_Type::saturday;
			this->date_index_to_day_type_[saturday_date_index + 1] = Day_Type::sunday;

			saturday_date_index += 7;

			if (Calender::num_day_in_year <= saturday_date_index) {
				break;
			}
			else if (saturday_date_index == last_date_index) {
				this->date_index_to_day_type_[last_date_index] = Day_Type::saturday;
				break;
			}
		}
	}

	void set_holiday(const std::vector<std::vector<int>>& holiday_dates)
	{
		const auto num_holiday = holiday_dates.size();
		const auto expect_max = num_holiday / 2;

		std::vector<int> saturday_start_holiday_date_index;
		std::vector<int> sunday_start_holiday_date_index;

		saturday_start_holiday_date_index.reserve(expect_max);
		sunday_start_holiday_date_index.reserve(expect_max);

		for (const auto& holiday_date : holiday_dates) {
			const auto month = holiday_date[0];
			const auto day = holiday_date[1];

			const auto holiday_date_index = this->cal_date_index(month, day);
			const auto day_type = this->date_index_to_day_type_[holiday_date_index];

			switch (day_type) {
			case Day_Type::work_day:
				this->date_index_to_day_type_[holiday_date_index] = Day_Type::holiday;
				break;
			case Day_Type::saturday: {
				saturday_start_holiday_date_index.push_back(holiday_date_index);
				break;
			}
			case Day_Type::sunday: {
				sunday_start_holiday_date_index.push_back(holiday_date_index);
				break;
			}
			default:
				throw std::runtime_error("set holiday error");
				break;
			}
		}

		// saturday
		constexpr auto first_date_index = 0;

		for (const auto date_index : saturday_start_holiday_date_index) {
			auto yesterday_date_index = date_index;
			while (true) {
				yesterday_date_index--;

				if (yesterday_date_index < first_date_index) {
					break;
				}

				const auto yesterday_date_type = this->date_index_to_day_type_[yesterday_date_index];

				if (yesterday_date_type == Day_Type::work_day) {
					this->date_index_to_day_type_[yesterday_date_index] = Day_Type::holiday;
					break;
				}
			}
		}

		// sunday
		constexpr auto last_date_index = 364;

		for (const auto date_index : sunday_start_holiday_date_index) {
			auto tomorrow_date_index = date_index;
			while (true) {
				tomorrow_date_index++;

				if (last_date_index < tomorrow_date_index) {
					break;
				}

				const auto tommorrow_date_type = this->date_index_to_day_type_[tomorrow_date_index];

				if (tommorrow_date_type == Day_Type::work_day) {
					this->date_index_to_day_type_[tomorrow_date_index] = Day_Type::holiday;
					break;
				}
			}
		}
	}

	int cal_date_index(const int month, const int day) const
	{
		const auto month_index = this->cal_month_index(month);
		return this->month_index_to_date_index_[month_index] + day - 1;
	}

	std::pair<int, int> to_month_day(const int date_index) const
	{
		auto month_index = 0;
		while (true) {
			if (date_index < this->month_index_to_date_index_[month_index]) {
				break;
			}

			month_index++;

			if (Calender::num_month_in_year == month_index) {
				break;
			}
		}

		auto month = month_index;
		auto day = date_index - this->month_index_to_date_index_[this->cal_month_index(month)] + 1;

		return { month, day };
	}

	int cal_month_index(const int month) const { return month - 1; }

	std::optional<int> find_right_before_work_day_date_index(const int date_index) const
	{
		constexpr auto first_date_index = 0;

		auto yesterday_date_index = date_index;
		while (true) {
			yesterday_date_index--;

			if (yesterday_date_index < first_date_index) {
				return std::nullopt;
			}

			const auto day_type = this->date_index_to_day_type_[yesterday_date_index];
			if (day_type == Day_Type::work_day) {
				return yesterday_date_index;
			}
		}
	}

	std::optional<int> find_next_longweekend_date_index(const int date_index) const
	{
		constexpr auto last_date_index = 364;

		auto tomorrow_date_index = date_index;
		while (true) {
			tomorrow_date_index++;

			if (last_date_index <= tomorrow_date_index) {
				return std::nullopt;
			}

			const auto today_day_type = this->date_index_to_day_type_[tomorrow_date_index - 1];
			const auto tomorrow_day_type = this->date_index_to_day_type_[tomorrow_date_index];
			if (today_day_type == Day_Type::work_day && tomorrow_day_type != Day_Type::work_day) {
				return tomorrow_date_index;
			}
		}
	}

	std::optional<int> find_right_after_work_day_date_index(const int date_index) const
	{
		constexpr auto last_date_index = 364;

		auto tomorrow_date_index = date_index;
		while (true) {
			tomorrow_date_index++;

			if (last_date_index <= tomorrow_date_index) {
				return std::nullopt;
			}

			const auto day_type = this->date_index_to_day_type_[tomorrow_date_index];
			if (day_type == Day_Type::work_day) {
				return tomorrow_date_index;
			}
		}
	}

private:
	static constexpr int num_day_in_year = 365;
	std::array<Day_Type, num_day_in_year> date_index_to_day_type_ = { Day_Type::work_day };

	static constexpr int num_month_in_year = 12;
	std::array<int, num_month_in_year> month_index_to_date_index_;
};
