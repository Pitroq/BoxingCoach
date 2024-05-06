#ifndef BOXING_SEQUENCE_GENERATOR_H
#define BOXING_SEQUENCE_GENERATOR_H

#include <vector>
#include <string>

extern int max_punches_count;
extern std::vector<std::string> punches;
int get_random_punch_number(int isEven);
int get_random_punch_number();
int get_random_length();
std::vector<int> generate_sequence();

#endif