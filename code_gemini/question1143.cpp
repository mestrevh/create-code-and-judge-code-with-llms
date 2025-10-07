/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    if (n == 0) {
        std::cout << 0 << std::endl;
        return 0;
    }

    std::vector<int> left(n);
    left[0] = 1;
    for (int i = 1; i < n; ++i) {
        left[i] = std::min(a[i], left[i - 1] + 1);
    }

    std::vector<int> right(n);
    right[n - 1] = 1;
    for (int i = n - 2; i >= 0; --i) {
        right[i] = std::min(a[i], right[i + 1] + 1);
    }

    int max_h = 0;
    for (int i = 0; i < n; ++i) {
        max_h = std::max(max_h, std::min(left[i], right[i]));
    }

    std::cout << max_h << std::endl;

    return 0;
}
