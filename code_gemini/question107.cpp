/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string s;
    while (std::cin >> s) {
        if (s == "0") {
            break;
        }

        long long n = std::stoll(s);

        if (n == 0) {
            std::cout << "[0]\n";
            continue;
        }
        
        while (n > 0) {
            std::cout << "[" << n % 10 << "]";
            n /= 10;
        }
        std::cout << "\n";
    }

    return 0;
}
