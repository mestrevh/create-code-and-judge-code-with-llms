/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>

std::string preprocess(const std::string& music) {
    std::string temp_processed;
    bool new_word = true;
    for (unsigned char c : music) {
        if (std::isspace(c)) {
            new_word = true;
        } else {
            if (new_word) {
                temp_processed += std::toupper(c);
                new_word = false;
            } else {
                temp_processed += std::tolower(c);
            }
        }
    }

    std::string final_substituted;
    for (char c : temp_processed) {
        switch (c) {
            case 'a': final_substituted += '@'; break;
            case 'E': final_substituted += '%'; break;
            case 'e': final_substituted += '!'; break;
            case 'i': final_substituted += '@'; break;
            case 'o': final_substituted += '#'; break;
            case 'u': final_substituted += '$'; break;
            default: final_substituted += c; break;
        }
    }
    return final_substituted;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string music_line;
    std::getline(std::cin, music_line);

    int n;
    std::cin >> n;

    std::string processed_text = preprocess(music_line);

    std::map<std::string, std::string> credentials;
    int passwords_saved_count = 0;
    int generation_attempt = 1;

    while (passwords_saved_count < n) {
        int magic_number;
        std::cin >> magic_number;

        std::string part1, part2, part3;

        part1 = processed_text.substr(generation_attempt, 5);
        part2 = processed_text.substr(processed_text.length() - 5, 5);
        part3 = processed_text.substr(magic_number, 5);
        
        std::string password = part1 + part2 + part3;
        std::reverse(password.begin(), password.end());

        std::cout << password << "\n";

        char choice;
        std::cin >> choice;

        if (choice == 's') {
            std::string username;
            std::cin >> username;
            credentials[username] = password;
            passwords_saved_count++;
        }
        
        generation_attempt++;
    }

    std::cout << "{";
    bool first_entry = true;
    for (const auto& pair : credentials) {
        if (!first_entry) {
            std::cout << ", ";
        }
        bool has_single_quote = pair.second.find('\'') != std::string::npos;
        std::cout << "'" << pair.first << "': ";
        if (has_single_quote) {
            std::cout << "\"" << pair.second << "\"";
        } else {
            std::cout << "'" << pair.second << "'";
        }
        first_entry = false;
    }
    std::cout << "}\n";

    return 0;
}
