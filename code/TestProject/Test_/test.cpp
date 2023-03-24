#include "gtest/gtest.h"

class A
{
public:
	virtual void test1(void) const { assert(false); };
	virtual void test2(void) const { assert(false); };
}; //이렇게 만들어 놓으면 안좋은게 현재 방법에서 빠진게 있나 없나 알 길이 없다 모든걸 파악하지 않는이상.

class B : public A
{
public:
	void test1(void) const override {};
};

TEST(test123,test123)
{
	B b;
	b.test1();
}