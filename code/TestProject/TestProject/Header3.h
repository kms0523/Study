#pragma once

template <typename T>
class A;

using AD = A<double>;

class B
{
public:
	void test(AD ad) const;
};

