#include <gtest/gtest.h>
#include "boxing_sequence_generator.h"

TEST(boxing_sequence_generator, get_random_punch_number) {
    EXPECT_EQ(get_random_punch_number(true, true) % 2 == 0, true);
    EXPECT_EQ(get_random_punch_number(true, false) % 2 == 0, false);
    EXPECT_EQ(get_random_punch_number(false, true) % 2 == 0, true);
    EXPECT_EQ(get_random_punch_number(false, false) % 2 == 0, false);

    EXPECT_LE(get_random_punch_number(true), PUNCHES.size());
    EXPECT_LE(get_random_punch_number(false), PUNCHES.size() - 4);
}

TEST(boxing_sequence_generator, get_random_length) {
    EXPECT_LE(get_random_length(2), 2);
    EXPECT_LE(get_random_length(5), 5);
    EXPECT_LE(get_random_length(0), 0);
}