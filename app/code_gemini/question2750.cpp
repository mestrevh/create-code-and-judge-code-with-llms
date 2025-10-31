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
    while (n--) {
        int x;
        std::cin >> x;
        if (x <= 1) {
            std::cout << x << " nao eh perfeito\n";
            continue;
        }
        long long sum = 1;
        for (int i = 2; i * i <= x; ++i) {
            if (x % i == 0) {
                sum += i;
                if (i * i != x) {
                    sum += (x / i);
                }
            }
        }
        if (sum == x) {
            std::cout << x << " eh perfeito\n";
        } else {
            std::cout << x << " nao eh perfeito\n";
        }
    }
    return 0;
}
