/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    while (std::cin >> n && n != -1) {
        long long factorial = 1;
        for (int i = 1; i <= n; ++i) {
            factorial *= i;
        }
        std::cout << factorial << '\n';
    }
    return 0;
}
