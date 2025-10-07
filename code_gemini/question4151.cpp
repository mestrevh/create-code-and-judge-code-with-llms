/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

std::string decodeCaesar(const std::string& encoded_msg, int key) {
    std::string decoded_msg = "";
    int effective_key = key % 26;
    if (effective_key < 0) {
        effective_key += 26;
    }

    for (char c : encoded_msg) {
        if (c >= 'A' && c <= 'Z') {
            char decoded_c = (char)(((c - 'A' - effective_key) + 26) % 26 + 'A');
            decoded_msg += decoded_c;
        } else if (c >= 'a' && c <= 'z') {
            char decoded_c = (char)(((c - 'a' - effective_key) + 26) % 26 + 'a');
            decoded_msg += decoded_c;
        } else {
            decoded_msg += c;
        }
    }
    return decoded_msg;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    char grid[12][12];
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 12; ++j) {
            grid[i][j] = 'o';
        }
    }

    int n;
    std::cin >> n;

    std::vector<std::string> decoded_messages;

    for (int i = 0; i < n; ++i) {
        int key;
        std::cin >> key;

        std::string encoded_msg;
        std::cin.get(); 
        std::getline(std::cin, encoded_msg);

        decoded_messages.push_back(decodeCaesar(encoded_msg, key));

        int col, row;
        std::cin >> col >> row;
        if (row >= 1 && row <= 12 && col >= 1 && col <= 12) {
            grid[row - 1][col - 1] = 'x';
        }
    }

    for (const auto& msg : decoded_messages) {
        std::cout << msg << "\n";
    }

    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 12; ++j) {
            std::cout << grid[i][j] << (j == 11 ? "" : " ");
        }
        std::cout << "\n";
    }

    return 0;
}
