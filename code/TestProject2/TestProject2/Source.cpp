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

//�Ϲ��Լ����� ���� �Լ��ΰſ���?

//�����Լ����� �մ� �Լ��ΰſ���?
//get_offset(func_name)
//{
//	  f1=1
//		f2=2
//		f3=0
//3

//�Ϲ��Լ��� ������ �ּҸ� �� ����
//�����Լ��� ������ ��ȣ�� �ȴ�.



int main(void)
{
	B b;
	b.f4();
	// adress of f4�� �˰� �ִ�.
	// call (adress of f4)

	std::unique_ptr<A> ptr = std::make_unique<B>();
	ptr->f1();		
	// f1 = 1  �̰� �׳� �˰� �ִ�. --> �̰� �𸥴�.
	// call ptr->vftable[1]
}