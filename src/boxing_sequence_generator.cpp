#include "boxing_sequence_generator.h"

#include <random>

const std::vector<std::string> PUNCHES = {
    "jab", "cross", 
    "hook", "rear hook",
    "uppercut", "rear uppercut",
    "body jab", "body cross",
    "body hook", "rear body hook"
};

int get_random_punch_number(bool include_body_punches, bool is_even) {
    int punch_number;
    if (include_body_punches) {
        punch_number = rand() % PUNCHES.size() + 1;
    }
    else {
        punch_number = rand() % (PUNCHES.size() - 4) + 1;
    }
    
    if (punch_number % 2 == is_even) {
        return get_random_punch_number(include_body_punches, is_even);
    }
    return punch_number;
}

int get_random_punch_number(bool include_body_punches) {
    if (include_body_punches) {
        return rand() % PUNCHES.size() + 1;
    }
    return rand() % (PUNCHES.size() - 4) + 1;
}

int get_random_length(int min_punches_count, int max_punches_count) {
    return rand() % max_punches_count + min_punches_count;
}

std::vector<int> generate_sequence(int min_punches_count, int max_punches_count, bool include_body_punches) {
    std::vector<int> sequence;
    sequence.push_back(get_random_punch_number(include_body_punches));
    for (int i = 1; i < get_random_length(min_punches_count, max_punches_count); i++) {
        bool isLastEven = sequence.back() % 2 == 0;
        int punch_number = get_random_punch_number(include_body_punches, !isLastEven);
        sequence.push_back(punch_number);
    }
    return sequence;
}