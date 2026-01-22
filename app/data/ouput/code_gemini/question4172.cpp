/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, k;
    std::cin >> n >> k;
    if (k > n - k) {
        k = n - k;
    }
    long long resultado = 1;
    for (int i = 0; i < k; ++i) {
        resultado = resultado * (n - i) / (i + 1);
    }
    std::cout << resultado << std::endl;
    return 0;
}
