/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    std::cin.ignore(); 

    while (n--) {
        std::string line;
        std::getline(std::cin, line);

        // Pass 1
        for (char &c : line) {
            if (std::isalpha(c)) {
                c += 3;
            }
        }

        // Pass 2
        std::reverse(line.begin(), line.end());

        // Pass 3
        int mid = line.length() / 2;
        for (int i = mid; i < line.length(); ++i) {
            line[i] -= 1;
        }

        std::cout << line << std::endl;
    }

    return 0;
}
