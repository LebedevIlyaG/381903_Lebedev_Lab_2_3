#include "Steck.h"

#include "../gtest/gtest.h"

TEST(TBitField, can_create_steck_with_positive_length)
{
  ASSERT_NO_THROW(TSteck<int> bf(3));
}
