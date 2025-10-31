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
    long long fatorial = 1;
    for (int i = 1; i <= n; ++i) {
        fatorial *= i;
    }
    std::cout << fatorial << std::endl;
    return 0;
}
