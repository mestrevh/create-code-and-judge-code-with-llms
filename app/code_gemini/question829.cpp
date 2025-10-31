/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::vector<char> chars(5);
    for (int i = 0; i < 5; ++i) {
        std::cin >> chars[i];
    }
    std::sort(chars.begin(), chars.end());
    for (int i = 1; i < 5; ++i) {
        if (chars[i] != chars[i - 1] + 1) {
            std::cout << "nao\n";
            return 0;
        }
    }
    std::cout << "sim\n";
    return 0;
}
