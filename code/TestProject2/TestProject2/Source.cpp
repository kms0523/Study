#include <memory>

class A
{
public:
	virtual void f1(void) {};
};

// A
// f1 = 0

class B : public A
{
public:
	virtual void f3(void) {};
	void f1(void) override {};
	virtual void f2(void) {};
	void f4(void) {};
};

// B
// f1 = 1
// f2 = 2
// f3 = 0

//일반함수에는 없는 함수인거에요?

//가상함수에만 잇는 함수인거에요?
//get_offset(func_name)
//{
//	  f1=1
//		f2=2
//		f3=0
//3

//일반함수가 본인의 주소를 알 듯이
//가상함수는 본인의 번호를 안다.



int main(void)
{
	B b;
	b.f4();
	// adress of f4는 알고 있다.
	// call (adress of f4)

	std::unique_ptr<A> ptr = std::make_unique<B>();
	ptr->f1();		
	// f1 = 1  이걸 그냥 알고 있다. --> 이걸 모른다.
	// call ptr->vftable[1]
}