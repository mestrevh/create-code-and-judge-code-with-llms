/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < n - i; ++j) {
            std::cout << ".";
        }
        std::cout << "&";
        for (int j = 1; j < i; ++j) {
            std::cout << "-&";
        }
        for (int j = 0; j < n - i; ++j) {
            std::cout << ".";
        }
        std::cout << "\n";
    }
    for (int i = 0; i < 2 * n - 1; ++i) {
        std::cout << "#";
    }
    std::cout << "\n";
    long long total_cost = (long long)n * (n + 1) / 2 * 200 + (long long)n * (n - 1) / 2 * 50 + (long long)(2 * n - 1) * 100;
    std::cout << "O valor total foi: " << total_cost << std::endl;
    return 0;
}
