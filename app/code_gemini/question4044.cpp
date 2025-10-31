/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string keyword;
    std::cin >> keyword;

    std::string encoded_message;
    std::getline(std::cin >> std::ws, encoded_message);

    long long ascii_sum = 0;
    for (char c : keyword) {
        ascii_sum += c;
    }
    int key = ascii_sum % 26;

    std::string decoded_message = "";
    size_t keyword_len = keyword.length();
    int letter_index = 0;

    for (char current_char : encoded_message) {
        if (current_char == '_') {
            decoded_message += ' ';
        } else if (current_char == '#') {
            decoded_message += '.';
        } else if (current_char == '&') {
            decoded_message += ',';
        } else if (current_char >= 'A' && current_char <= 'Z') {
            char keyword_char = keyword[letter_index % keyword_len];
            int pos_keyword = keyword_char - 'A';
            int dist = std::abs(pos_keyword - key);
            int pos_encoded = current_char - 'A';
            int pos_decoded = (pos_encoded - dist + 26) % 26;
            decoded_message += (char)('A' + pos_decoded);
            letter_index++;
        }
    }

    std::cout << decoded_message << std::endl;

    return 0;
}
