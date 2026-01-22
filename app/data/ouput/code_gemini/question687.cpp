/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    for (int i = 0; i <= n; ++i) {
        long long val = 1;
        for (int j = 0; j <= i; ++j) {
            std::cout << val << (j == i ? "" : " ");
            val = val * (long long)(i - j) / (j + 1);
        }
        std::cout << "\n";
    }
    return 0;
}
