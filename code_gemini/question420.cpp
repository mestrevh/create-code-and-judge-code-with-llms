/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

const std::string PLAINTEXT = "the quick brown fox jumps over the lazy dog";

bool build_map(const std::string& encrypted, char c_to_p_map[]) {
    if (encrypted.length() != PLAINTEXT.length()) {
        return false;
    }

    char p_to_c_map[26] = {0};
    for(int i = 0; i < 26; ++i) {
        c_to_p_map[i] = 0;
    }

    for (size_t i = 0; i < PLAINTEXT.length(); ++i) {
        char p_char = PLAINTEXT[i];
        char e_char = encrypted[i];

        if (p_char == ' ') {
            if (e_char != ' ') return false;
            continue;
        }
        
        if (e_char == ' ') return false;

        int p_idx = p_char - 'a';
        int e_idx = e_char - 'a';

        if ((p_to_c_map[p_idx] != 0 && p_to_c_map[p_idx] != e_char) ||
            (c_to_p_map[e_idx] != 0 && c_to_p_map[e_idx] != p_char)) {
            return false;
        }
        
        p_to_c_map[p_idx] = e_char;
        c_to_p_map[e_idx] = p_char;
    }

    return true;
}

void solve() {
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(std::cin, line) && !line.empty()) {
        lines.push_back(line);
    }

    bool found_solution = false;
    char decrypt_map[26] = {0};

    for (const auto& candidate : lines) {
        if (build_map(candidate, decrypt_map)) {
            found_solution = true;
            break;
        }
    }

    if (found_solution) {
        for (const auto& l : lines) {
            for (char c : l) {
                if (c == ' ') {
                    std::cout << c;
                } else {
                    std::cout << decrypt_map[c - 'a'];
                }
            }
            std::cout << '\n';
        }
    } else {
        std::cout << "No solution.\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int num_cases;
    std::cin >> num_cases;
    std::cin.ignore(256, '\n'); 
    std::cin.ignore(256, '\n'); 

    for (int i = 0; i < num_cases; ++i) {
        if (i > 0) {
            std::cout << '\n';
        }
        solve();
    }

    return 0;
}
