#include "gtest/gtest.h"
#include <iomanip>
#include <fstream>

TEST(test1, test1)
{
	std::ofstream of("test.txt");

  of << "    ELEMENT    GRID    SURFACE     NORMALIZED CUMULATIVE STRAIN ENERGY\n"
		 << "      ID        ID	    \n";


	constexpr int elem_id = 1;
	std::vector<float> values = { 1.0, 2.0345, 1.2355123e-13 };
	const auto num_output_location = values.size();

	constexpr int num_decimical_places = 6;
	of << std::scientific << std::setprecision(num_decimical_places);

	of << std::setw(8) << elem_id << std::setw(12) << "CENTER" << "         ";
	of << std::setw(13) << values[0] << "  ";
	of << "\n";

	for (auto j = 1; j < num_output_location; ++j)
	{
		const auto corner_id = 23;
		const auto corner_values = values[j];

		of << std::setw(20) << corner_id << "         ";
		of << std::setw(13) << values[j] << "  ";
		of << "\n";
	}
};