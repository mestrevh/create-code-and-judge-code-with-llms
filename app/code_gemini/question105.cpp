/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <limits>

std::vector<std::string> dictionary_by_len[17];
std::vector<std::string> encoded_words;
char mapping[26];
bool used_char[26];

bool solve(int word_idx) {
    if (word_idx == encoded_words.size()) {
        return true;
    }

    const std::string& enc_word = encoded_words[word_idx];
    size_t len = enc_word.length();

    const auto& candidates = dictionary_by_len[len];
    for (const std::string& dict_word : candidates) {
        char old_mapping[26];
        bool old_used_char[26];
        memcpy(old_mapping, mapping, sizeof(mapping));
        memcpy(old_used_char, used_char, sizeof(used_char));

        bool possible = true;
        for (size_t i = 0; i < len; ++i) {
            int enc_c_idx = enc_word[i] - 'a';
            char dict_c = dict_word[i];
            int dict_c_idx = dict_c - 'a';

            if (mapping[enc_c_idx] != 0 && mapping[enc_c_idx] != dict_c) {
                possible = false;
                break;
            }
            if (mapping[enc_c_idx] == 0 && used_char[dict_c_idx]) {
                possible = false;
                break;
            }
            
            mapping[enc_c_idx] = dict_c;
            used_char[dict_c_idx] = true;
        }

        if (possible) {
            if (solve(word_idx + 1)) {
                return true;
            }
        }
        
        memcpy(mapping, old_mapping, sizeof(mapping));
        memcpy(used_char, old_used_char, sizeof(used_char));
    }

    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::string word;
    for (int i = 0; i < n; ++i) {
        std::cin >> word;
        dictionary_by_len[word.length()].push_back(word);
    }
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string line;
    while (getline(std::cin, line)) {
        if (line.empty()) {
            continue;
        }

        encoded_words.clear();
        std::stringstream ss(line);
        while (ss >> word) {
            encoded_words.push_back(word);
        }

        std::sort(encoded_words.begin(), encoded_words.end(), 
                  [](const std::string& a, const std::string& b) {
                      return a.length() > b.length();
                  });

        memset(mapping, 0, sizeof(mapping));
        memset(used_char, 0, sizeof(used_char));

        if (solve(0)) {
            for (char c : line) {
                if (c == ' ') {
                    std::cout << ' ';
                } else {
                    std::cout << mapping[c - 'a'];
                }
            }
            std::cout << "\n";
        } else {
            for (char c : line) {
                if (c == ' ') {
                    std::cout << ' ';
                } else {
                    std::cout << '*';
                }
            }
            std::cout << "\n";
        }
    }

    return 0;
}
