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
    unsigned long long b;

    std::cin >> n >> b;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int index = i * n + j;
            if ((b >> index) & 1) {
                std::cout << 'x';
            } else {
                std::cout << '-';
            }
        }
        std::cout << '\n';
    }

    return 0;
}
