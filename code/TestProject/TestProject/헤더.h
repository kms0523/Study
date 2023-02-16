#pragma once
#include <cassert>
#include <iostream>

//// lean version
//class Common_Base
//{
//	// method for A
//public:
//	virtual void A1(void) { assert(false); };
//	virtual void A2(void) { assert(false); };
//
//	// method for B
//public:
//	virtual void B1(void) { assert(false); };
//	virtual void B2(void) { assert(false); };
//};
//
//class A_impl1 : public Common_Base
//{
//	void A1(void) override { std::cout << "A1 in A_impl1\n"; };
//	void A2(void) override { std::cout << "A2 in A_impl1\n"; };
//};
//
//class B_impl1 : public Common_Base
//{
//	void B1(void) override { std::cout << "B1 in B_impl1\n"; };
//	void B2(void) override { std::cout << "B2 in B_impl1\n"; };
//};

class Common_Base
{
//이렇게 만들어 놓을 수는 있지만 반드시 필요한것은 아니다.
//가독성을 생각한다면 있는것도 나쁘지 않다.
public:
	virtual bool is_A(void) = 0;
	virtual bool is_B(void) = 0;

	// method for A
public:
	virtual void A1(void) { assert(false); };
	virtual void A2(void) { assert(false); };

	// method for B
public:
	virtual void B1(void) { assert(false); };
	virtual void B2(void) { assert(false); };
};

class Common_Base_A : public Common_Base
{
public:
	bool is_A(void) override { return true; };
	bool is_B(void) override { return false; };
};

class Common_Base_B : public Common_Base
{
public:
	bool is_A(void) override { return false; };
	bool is_B(void) override { return true; };
};

class A_impl1 : public Common_Base_A
{
	void A1(void) override { std::cout << "A1 in A_impl1\n"; };
	void A2(void) override { std::cout << "A2 in A_impl1\n"; };
};

class B_impl1 : public Common_Base_B
{
	void B1(void) override { std::cout << "B1 in B_impl1\n"; };
	void B2(void) override { std::cout << "B2 in B_impl1\n"; };
};