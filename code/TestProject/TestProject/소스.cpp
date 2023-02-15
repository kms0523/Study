#pragma once

//#include "헤더1.h"
//
//int main(void) {
//	
//	
//}

#include "헤더1.h"
#include "헤더2.h"

int main(void) {
	Z<int> a; 
	a.Ztest();

	X<int> b;
	b.Xtest1();

	testfunction();
	testinlinefunction();
	teststaticfunction();
}
