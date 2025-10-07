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
    std::cin >> n;

    std::vector<std::string> original(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> original[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char c = original[j][i];
            if (c >= 'a' && c <= 'z') {
                c = 'a' + (c - 'a' + 2) % 26;
            }
            std::cout << c;
        }
        std::cout << '\n';
    }

    return 0;
}
