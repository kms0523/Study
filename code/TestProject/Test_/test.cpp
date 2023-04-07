#include "gtest/gtest.h"
#include "../TestProject/Header3.h"
#include "../TestProject/Header4.h"

enum class Alphabet
{
A,
B
};

TEST(test123,test123)
{
	Alphabet alphabet;

	if (alphabet == Alphabet::A)
	{
		std::cout << "is A";
	}
	else if (alphabet == Alphabet::B)
	{
		std::cout << "is B";
	}
	else
	{
		std::cout << "Something..";
	}

}