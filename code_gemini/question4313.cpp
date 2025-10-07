/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<std::string> passwords(n);
    bool all_valid = true;

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
    }

    if (!all_valid) {
        std::cout << "Alguma senha eh invalida!\n";
        return 0;
    }

    long long total_chars = 0;
    std::string final_output = "";

    for (const std::string& password : passwords) {
        total_chars += password.length();
        std::string encrypted_s = "";
        for (char c : password) {
            char encrypted_char = c;
            switch (c) {
                case 'A': encrypted_char = '0'; break;
                case 'B': encrypted_char = 'D'; break;
                case 'C': encrypted_char = 'E'; break;
                case 'D': encrypted_char = '3'; break;
                case 'F': encrypted_char = '4'; break;
                case '0': encrypted_char = '6'; break;
                case '1': encrypted_char = '7'; break;
                case '2': encrypted_char = '9'; break;
                case '3': encrypted_char = '8'; break;
                case '4': encrypted_char = 'A'; break;
                case '5': encrypted_char = '2'; break;
                case '6': encrypted_char = 'B'; break;
                case '7': encrypted_char = 'F'; break;
                case '8': encrypted_char = '1'; break;
                case '9': encrypted_char = 'C'; break;
            }
            encrypted_s += encrypted_char;
        }
        final_output += "-" + encrypted_s;
    }

    std::cout << final_output << " " << total_chars << "\n";

    return 0;
}
