#pragma once

#include <chrono>
#include <iostream>
#include <vector>

class Profiler
{
public:
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