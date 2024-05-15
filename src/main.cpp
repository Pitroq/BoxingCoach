#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <windows.h>

#include "boxing_sequence_generator.h"

void sleep(int seconds) {
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

int min_punches_count = 3;
int max_punches_count = 5;
int combinations_count = 100;

int punch_sleep_time = 0.5;
int combination_sleep_time = 2;

bool include_body_punches = false;

int main() {
    srand(time(NULL));

    for (int i = 0; i < combinations_count; i++) {
        std::vector<int> sequence = generate_sequence(min_punches_count, max_punches_count, include_body_punches);
        for (auto punch_number : sequence) {
            std::cout << punch_number << " - " << PUNCHES[punch_number - 1] << '\n';
            std::string audio_path = "audio/punch" + std::to_string(punch_number) + "-name.wav";
            PlaySoundA(audio_path.c_str(), NULL, SND_FILENAME);
            sleep(punch_sleep_time);
        }
        std::cout << "--------------------\n";
        sleep(combination_sleep_time);
    }

    return 0;
}