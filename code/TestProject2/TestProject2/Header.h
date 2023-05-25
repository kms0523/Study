#pragma once
#include <iostream>

static void test_static(void)
{
	std::cout << test_static << "\n";
};

inline void test_inline(void)
{
	std::cout << test_inline << "\n";
};