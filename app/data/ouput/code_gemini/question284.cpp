/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    if (n == 0) {
        std::cout << 10 << std::endl;
        return 0;
    }
    if (n == 1) {
        std::cout << 1 << std::endl;
        return 0;
    }
    std::vector<int> digits;
    for (int d = 9; d >= 2; --d) {
        while (n % d == 0) {
            digits.push_back(d);
            n /= d;
        }
    }
    if (n > 1) {
        std::cout << -1 << std::endl;
    } else {
        std::sort(digits.begin(), digits.end());
        for (int digit : digits) {
            std::cout << digit;
        }
        std::cout << std::endl;
    }
    return 0;
}
