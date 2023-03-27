#include "gtest/gtest.h"
#include <iomanip>
#include <fstream>

TEST(test1, test1)
{
	std::ofstream of("test.txt");

	of << std::setw(10) << "ELEMENT" << std::setw(10) << "GRID" << std::setw(50) << "NORMALIZED CUMULATIVE STRAIN ENERGY\n";
	of << std::setw(7) << "ID" << std::setw(7) << "ID\n";

	//of << "    ELEMENT    GRID     NORMALIZED CUMULATIVE STRAIN ENERGY\n"
	//	 << "      ID        ID	     \n";

	constexpr int elem_id = 1;
	std::vector<float> values = { 1.0, 2.0345, 1.2355123e-13 };

	constexpr int num_decimical_places = 6;
	of << std::scientific << std::setprecision(num_decimical_places);

	of << "      " << elem_id << "       CENTER      ";
	for (auto val : values)
	{
		of << val << "  ";
	}
	of << "\n";
};