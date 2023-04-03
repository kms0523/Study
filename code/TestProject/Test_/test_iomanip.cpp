#include "gtest/gtest.h"
#include <iomanip>
#include <fstream>

TEST(test1, test1)
{
	constexpr auto space3 = "   ";

	std::ofstream of("iomaniptest.txt");


	of << "123456789\n";
	of << space3 << std::setw(2) << "1234";
	of << "\n";
	of << space3 << std::setw(2) << "1";
	of << "\n";
	of << std::setw(5) << "1";
};