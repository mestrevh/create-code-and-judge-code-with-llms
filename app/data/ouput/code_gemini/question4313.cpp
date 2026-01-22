/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<std::string> passwords(n);
    bool all_valid = true;
    long long total_chars = 0;

    for (int i = 0; i < n; ++i) {
        std::cin >> passwords[i];
        if (all_valid) {
            for (char c : passwords[i]) {
                if (!((c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))) {
                    all_valid = false;
                    break;
                }
            }
        }
        total_chars += passwords[i].length();
    }

    if (!all_valid) {
        std::cout << "Alguma senha eh invalida!\n";
    } else {
        for (const auto& password : passwords) {
            std::cout << "-";
            for (char c : password) {
                char encrypted_char = c;
                switch (c) {
                    case '0': encrypted_char = '6'; break;
                    case '1': encrypted_char = '7'; break;
                    case '2': encrypted_char = '9'; break;
                    case '3': encrypted_char = '8'; break;
                    case '4': encrypted_char = 'A'; break;
                    case '5': encrypted_char = 'B'; break;
                    case '6': encrypted_char = 'E'; break;
                    case '7': encrypted_char = 'F'; break;
                    case '8': encrypted_char = '1'; break;
                    case '9': encrypted_char = 'C'; break;
                    case 'A': encrypted_char = '0'; break;
                    case 'B': encrypted_char = 'D'; break;
                    case 'C': encrypted_char = 'E'; break;
                    case 'D': encrypted_char = '3'; break;
                    case 'F': encrypted_char = '4'; break;
                }
                std::cout << encrypted_char;
            }
        }
        std::cout << " " << total_chars << "\n";
    }

    return 0;
}
