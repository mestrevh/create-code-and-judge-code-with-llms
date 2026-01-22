/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    if (n < 0) {
        std::cout << "O valor informado para N foi negativo\n";
    } else if (n == 0) {
        std::cout << "Lista vazia - O valor de S eh zero\n";
    } else {
        std::vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }

        long long s = 0;
        for (int i = 0; i < n / 2; ++i) {
            long long diff = a[i] - a[n - 1 - i];
            s += diff * diff;
        }

        if (n % 2 != 0) {
            s += a[n / 2] * a[n / 2];
        }

        std::cout << "S = " << s << "\n";
    }

    return 0;
}
