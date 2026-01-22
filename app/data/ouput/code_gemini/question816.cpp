/*
Código criado pelo Gemini Pro 2.5
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
    std::string line;
    std::getline(std::cin, line); // Consume the newline after reading n

    int balance = 0;

    for (int i = 0; i < n; ++i) {
        std::getline(std::cin, line);
        for (char c : line) {
            if (c == '{') {
                balance++;
            } else if (c == '}') {
                balance--;
            }
            if (balance < 0) {
                std::cout << "N" << std::endl;
                return 0;
            }
        }
    }

    if (balance == 0) {
        std::cout << "S" << std::endl;
    } else {
        std::cout << "N" << std::endl;
    }

    return 0;
}
