#include "gtest/gtest.h"

class A
{
public:
	virtual void test1(void) const { assert(false); };
	virtual void test2(void) const { assert(false); };
}; //�̷��� ����� ������ �������� ���� ������� ������ �ֳ� ���� �� ���� ���� ���� �ľ����� �ʴ��̻�.

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