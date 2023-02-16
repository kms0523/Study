#pragma once

#include <memory>

#include "Çì´õ.h"


int main(void) {
	std::unique_ptr<Common_Base> ptr = std::make_unique<A_impl1>();
	assert(ptr->is_A());
	ptr->A1();
	ptr->A2();

	std::unique_ptr<Common_Base> ptr2 = std::make_unique<B_impl1>();
	assert(ptr2->is_B());
	ptr2->B1();
	ptr2->B2();
}
