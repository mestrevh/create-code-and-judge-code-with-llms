/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long n, m;
    if (!(std::cin >> n >> m)) return 0;

    if (n <= m) {
        long long start;
        if (n % 5 == 0) {
            start = n;
        } else if (n > 0) {
            start = n + (5 - (n % 5));
        } else {
            start = n - (n % 5);
        }

        bool first = true;
        for (long long i = start; i <= m; i += 5) {
            if (!first) {
                std::cout << "|";
            }
            std::cout << i;
            first = false;
            if (i > m - 5) break;
        }
        if (!first) {
            std::cout << "\n";
        }
    }

    return 0;
}