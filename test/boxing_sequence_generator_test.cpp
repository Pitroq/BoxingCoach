#include <gtest/gtest.h>
#include "boxing_sequence_generator.h"

#include <iostream>

TEST(boxing_sequence_generator, get_random_punch_number) {
    EXPECT_EQ(get_random_punch_number(true, true) % 2 == 0, true);
    EXPECT_EQ(get_random_punch_number(true, false) % 2 == 0, false);
    EXPECT_EQ(get_random_punch_number(false, true) % 2 == 0, true);
    EXPECT_EQ(get_random_punch_number(false, false) % 2 == 0, false);

    EXPECT_LE(get_random_punch_number(true), PUNCHES.size());
    EXPECT_LE(get_random_punch_number(false), PUNCHES.size() - 4);
}

TEST(boxing_sequence_generator, get_random_length) {
    int len;
    len = get_random_length(1, 2);
    EXPECT_GE(len, 1);
    EXPECT_LE(len, 2);

    len = get_random_length(6, 1);
    EXPECT_GE(len, 1);
    EXPECT_LE(len, 6);
}