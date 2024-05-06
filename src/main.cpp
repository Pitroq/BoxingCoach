#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <windows.h>

#include "boxing_sequence_generator.h"

void sleep(int seconds) {
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

int main() {
    srand(time(NULL));
    std::vector<int> sequence = generate_sequence();
    for (auto punch_number : sequence) {
        std::cout << punch_number << " - " << punches[punch_number - 1] << '\n';
        std::string audio_path = "audio/punch" + std::to_string(punch_number) + "-name.wav";
        PlaySoundA(audio_path.c_str(), NULL, SND_FILENAME);
        sleep(0.5);
    }
    return 0;
}