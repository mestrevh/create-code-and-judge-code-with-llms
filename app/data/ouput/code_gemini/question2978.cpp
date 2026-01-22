/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    while (std::cin >> n && n != 0) {
        std::vector<int> bits(32, -1);

        for (int k = 0; k < n; ++k) {
            std::string command;
            std::cin >> command;

            if (command == "SET") {
                int i;
                std::cin >> i;
                bits[i] = 1;
            } else if (command == "CLEAR") {
                int i;
                std::cin >> i;
                bits[i] = 0;
            } else if (command == "OR") {
                int i, j;
                std::cin >> i >> j;
                
                if (bits[i] == 1 || bits[j] == 1) {
                    bits[i] = 1;
                } else if (bits[i] == 0 && bits[j] == 0) {
                    bits[i] = 0;
                } else {
                    bits[i] = -1;
                }
            } else if (command == "AND") {
                int i, j;
                std::cin >> i >> j;
                
                if (bits[i] == 0 || bits[j] == 0) {
                    bits[i] = 0;
                } else if (bits[i] == 1 && bits[j] == 1) {
                    bits[i] = 1;
                } else {
                    bits[i] = -1;
                }
            }
        }
        
        for (int i = 31; i >= 0; --i) {
            if (bits[i] == 1) {
                std::cout << '1';
            } else if (bits[i] == 0) {
                std::cout << '0';
            } else {
                std::cout << '?';
            }
        }
        std::cout << '\n';
    }

    return 0;
}
