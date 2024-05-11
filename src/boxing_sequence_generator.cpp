#include "boxing_sequence_generator.h"

const std::vector<std::string> PUNCHES = {
    "jab", "cross", 
    "hook", "rear hook",
    "uppercut", "rear uppercut",
    "body jab", "body cross",
    "body hook", "rear body hook"
};

int get_random_punch_number(int isEven) {
    int punch_number = (rand() % PUNCHES.size()) + 1;
    if (punch_number % 2 == isEven) {
        return get_random_punch_number(isEven);
    }
    return punch_number;
}

int get_random_punch_number() {
    return (rand() % PUNCHES.size()) + 1;
}

int get_random_length(int max_punches_count) {
    return (rand() % max_punches_count) + 1;
}

std::vector<int> generate_sequence(int max_punches_count) {
    std::vector<int> sequence;
    sequence.push_back(get_random_punch_number());
    for (int i = 1; i < get_random_length(max_punches_count); i++) {
        bool isLastEven = sequence.back() % 2 == 0;
        int punch_number = get_random_punch_number(!isLastEven);
        sequence.push_back(punch_number);
    }
    return sequence;
}