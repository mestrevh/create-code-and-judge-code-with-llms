/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    if (!(std::cin >> n)) {
        return 0;
    }

    std::vector<std::string> passwords(n);
    long long total_length = 0;
    bool any_invalid = false;

    for (int i = 0; i < n; ++i) {
        if (!(std::cin >> passwords[i])) {
            break;
        }
        total_length += passwords[i].length();
        for (const char c : passwords[i]) {
            if (!((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z'))) {
                any_invalid = true;
                break;
            }
        }
    }

    if (any_invalid) {
        std::cout << "Alguma senha eh invalida!\n";
    } else {
        auto encrypt = [](const char c) -> char {
            switch (c) {
                case '0': return '6';
                case '1': return '7';
                case '2': return '9';
                case '3': return '8';
                case '4': return 'A';
                case '5': return '2';
                case '6': return 'B';
                case '7': return 'F';
                case '8': return '1';
                case '9': return 'C';
                case 'A': return '0';
                case 'B': return 'D';
                case 'C': return 'E';
                case 'D': return '3';
                case 'E': return '5';
                case 'F': return '4';
                default:  return c;
            }
        };

        for (int i = 0; i < n; ++i) {
            std::cout << '-';
            for (const char c : passwords[i]) {
                std::cout << encrypt(c);
            }
        }
        std::cout << ' ' << total_length << '\n';
    }

    return 0;
}