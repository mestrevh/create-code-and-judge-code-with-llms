/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, x;
    std::cin >> n >> x;

    int k;
    if ((n - 2) % 2 != 0) {
        k = n - 2;
    } else {
        k = n - 3;
    }

    int m = (n - 1) - k;
    int d1 = x ^ 1;

    std::cout << d1;

    for (int i = 0; i < m; ++i) {
        std::cout << " " << 0;
    }

    for (int i = 0; i < k; ++i) {
        std::cout << " " << 1;
    }

    std::cout << std::endl;

    return 0;
}
