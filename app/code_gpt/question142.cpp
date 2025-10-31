/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

int note_to_index(const std::string &note) {
    static std::unordered_map<std::string, int> note_map = {
        {"A", 0}, {"A#", 1}, {"Bb", 1},
        {"B", 2},
        {"C", 3}, {"C#", 4}, {"Db", 4},
        {"D", 5}, {"D#", 6}, {"Eb", 6},
        {"E", 7},
        {"F", 8}, {"F#", 9}, {"Gb", 9},
        {"G", 10}, {"G#", 11}, {"Ab", 11}
    };
    return note_map[note];
}

std::vector<int> transform_melody(const std::vector<std::string> &melody, int offset) {
    std::vector<int> transformed;
    for (const auto &note : melody) {
        transformed.push_back((note_to_index(note) + offset) % 12);
    }
    return transformed;
}

bool check_plagiarism(const std::vector<int> &music, const std::vector<int> &suspect) {
    int m = music.size(), t = suspect.size();
    if (t > m) return false;

    for (int i = 0; i < 12; ++i) {
        std::vector<int> adjusted_suspect = transform_melody(suspect, i);
        for (int j = 0; j <= m - t; ++j) {
            if (std::equal(adjusted_suspect.begin(), adjusted_suspect.end(), music.begin() + j)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int M, T;
    while (std::cin >> M >> T, M || T) {
        std::vector<std::string> music(M);
        std::vector<std::string> suspect(T);
        for (int i = 0; i < M; ++i) std::cin >> music[i];
        for (int i = 0; i < T; ++i) std::cin >> suspect[i];

        std::vector<int> music_indices(M);
        for (int i = 0; i < M; ++i) music_indices[i] = note_to_index(music[i]);

        std::cout << (check_plagiarism(music_indices, transform_melody(suspect, 0)) ? 'S' : 'N') << '\n';
    }
    return 0;
}
