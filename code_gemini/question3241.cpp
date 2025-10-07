/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    int initial_ones = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        if (a[i] == 1) {
            initial_ones++;
        }
    }

    if (initial_ones == n) {
        std::cout << n - 1 << std::endl;
        return 0;
    }

    int max_gain = 0;
    int current_gain = 0;

    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) {
            current_gain++;
        } else {
            current_gain--;
        }

        if (current_gain < 0) {
            current_gain = 0;
        }

        max_gain = std::max(max_gain, current_gain);
    }

    std::cout << initial_ones + max_gain << std::endl;

    return 0;
}
