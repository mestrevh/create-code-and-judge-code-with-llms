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

    if (n <= 1) {
        return 0;
    }

    std::vector<long long> sum_divs(n, 0);

    for (int i = 1; i < n; ++i) {
        for (int j = i; j < n; j += i) {
            sum_divs[j] += i;
        }
    }

    for (int i = 2; i < n; ++i) {
        if (sum_divs[i] == 2LL * i) {
            std::cout << i << "\n";
        }
    }

    return 0;
}
