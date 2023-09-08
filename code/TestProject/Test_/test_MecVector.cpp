#include "gtest/gtest.h"

#include "../TestProject/mec/MecVector.h"


TEST(Vector, constructor)
{
	Mec::RealVector3 beta1;
	beta1 = 1.0, 2.0, 3.0; // formular csys x basis
}