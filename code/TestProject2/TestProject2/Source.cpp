#include <memory>

class A{};

class B : public A {};

int main(void)
{
	std::unique_ptr<A> ptr = std::make_unique<B>();

	
		
}