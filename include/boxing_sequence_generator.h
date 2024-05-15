#ifndef BOXING_SEQUENCE_GENERATOR_H
#define BOXING_SEQUENCE_GENERATOR_H

#include <vector>
#include <string>

const extern std::vector<std::string> PUNCHES;
int get_random_punch_number(bool include_body_punches, bool is_even);
int get_random_punch_number(bool include_body_punches);
int get_random_length(int min_punches_count, int max_punches_count);
std::vector<int> generate_sequence(int min_punches_count, int max_punches_count, bool include_body_punches);

#endif