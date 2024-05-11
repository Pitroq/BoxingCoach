#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <windows.h>

#include "boxing_sequence_generator.h"

void sleep(int seconds) {
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

int max_punches_count = 5;
int combinations_count = 5;

int punch_sleep_time = 1;
int combination_sleep_time = 2;

int main() {
    srand(time(NULL));

    for (int i = 0; i < combinations_count; i++) {
        std::vector<int> sequence = generate_sequence(max_punches_count);
        for (auto punch_number : sequence) {
            std::cout << punch_number << " - " << PUNCHES[punch_number - 1] << '\n';
            std::string audio_path = "audio/punch" + std::to_string(punch_number) + "-name.wav";
            PlaySoundA(audio_path.c_str(), NULL, SND_FILENAME);
            sleep(punch_sleep_time);
        }
        std::cout << "-------\n";
        sleep(combination_sleep_time);
    }

    
    return 0;
}