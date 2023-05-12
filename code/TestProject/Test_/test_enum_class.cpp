#include "gtest/gtest.h"
#include <map>


TEST(enum_class, numbering)
{
  enum class A
  {
    NOT_IN_LIST = -1,
    A,
    B = 5,
    C,
    NUM,
  };

	// If the NUMBER of the middle ELEMENT is determined, then the NUMBERING is recalculated based on that value.
  EXPECT_EQ(static_cast<int>(A::NUM), 7);
}
