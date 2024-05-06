#include <gtest/gtest.h>
#include "boxing_sequence_generator.h"

TEST(boxing_sequence_generator, get_random_punch_number) {
    EXPECT_EQ(get_random_punch_number(true) % 2 == 0, true);
    EXPECT_EQ(get_random_punch_number(false) % 2 == 0, false);
}
