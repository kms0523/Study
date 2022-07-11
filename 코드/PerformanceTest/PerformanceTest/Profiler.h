#pragma once

#include <chrono>
#include <iostream>
#include <vector>

using time_point = std::chrono::steady_clock::time_point;

class Profiler
{
public:
	static inline time_point get_time_point(void)
	{
		return std::chrono::steady_clock::now();
	}
	static inline double calculate_duration(const time_point& tp1, const time_point& tp2)
	{
		std::chrono::duration<double> time_duration = tp2 - tp1;
		return time_duration.count();
	}

	static void set_time_point(void);
	static double get_time_duration(void);

private:
	static inline std::vector<std::chrono::steady_clock::time_point> time_points_;
};


void Profiler::set_time_point(void) {
	time_points_.push_back(std::chrono::steady_clock::now());
}

double Profiler::get_time_duration(void) {
	std::chrono::duration<double> time_duration = std::chrono::steady_clock::now() - time_points_.back();
	time_points_.pop_back();
	return time_duration.count();
}