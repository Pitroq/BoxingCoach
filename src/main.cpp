#include <iostream>
#include <string>
#include "boxing_sequence_generator.h"

int main() {
    srand(time(NULL));
    std::vector<int> sequence = generate_sequence();
    for (auto punch_number : sequence) {
        std::cout << punch_number << " - " << punches[punch_number - 1] << '\n';
    }
    return 0;
}