/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <numeric>

void print_justified_line(const std::vector<std::string>& line_words, int C) {
    int num_words = line_words.size();
    
    if (num_words == 1) {
        std::cout << line_words[0];
        std::cout << std::string(C - line_words[0].length(), ' ');
        std::cout << '\n';
        return;
    }
    
    int total_word_len = 0;
    for (const auto& word : line_words) {
        total_word_len += word.length();
    }

    int total_spaces = C - total_word_len;
    int num_gaps = num_words - 1;
    
    int base_spaces = total_spaces / num_gaps;
    int extra_spaces = total_spaces % num_gaps;

    std::cout << line_words[0];
    for (int i = 0; i < num_gaps; ++i) {
        int spaces_to_print = base_spaces + (i < extra_spaces ? 1 : 0);
        std::cout << std::string(spaces_to_print, ' ');
        std::cout << line_words[i + 1];
    }
    std::cout << '\n';
}

void print_last_line(const std::vector<std::string>& line_words) {
    if (line_words.empty()) {
        return;
    }
    std::cout << line_words[0];
    for (size_t i = 1; i < line_words.size(); ++i) {
        std::cout << ' ' << line_words[i];
    }
    std::cout << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int P, C;
    std::cin >> P >> C;

    std::vector<std::string> words(P);
    for (int i = 0; i < P; ++i) {
        std::cin >> words[i];
    }

    int word_idx = 0;
    while (word_idx < P) {
        std::vector<std::string> current_line;
        int current_len_of_words = 0;
        
        current_line.push_back(words[word_idx]);
        current_len_of_words += words[word_idx].length();
        word_idx++;

        while (word_idx < P && (current_len_of_words + words[word_idx].length() + current_line.size() <= C)) {
            current_line.push_back(words[word_idx]);
            current_len_of_words += words[word_idx].length();
            word_idx++;
        }

        if (word_idx == P) {
            print_last_line(current_line);
        } else {
            print_justified_line(current_line, C);
        }
    }

    return 0;
}
