#include "gtest/gtest.h"
#include <iomanip>
#include <fstream>


TEST(test1,test1)
{
	constexpr int num_decimical_places = 3;

	std::ofstream of("test.txt");

	of << std::scientific << std::setprecision(num_decimical_places);	
	of << std::setw(10) << 1.0<< std::setw(10) << 2<< std::setw(10) << 3 << "\n";
	of << std::setw(15) << 1.234567 << std::setw(15) << 123.456789 << std::setw(15) << 0.000123;
};