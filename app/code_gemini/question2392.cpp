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

    std::vector<int> rain_l(n);
    std::vector<int> rain_r(n);

    int val;
    for (int i = 0; i < n; ++i) {
        std::cin >> val;
        rain_l[i] = 1 - val;
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> val;
        rain_r[i] = 1 - val;
    }

    std::vector<int> prefix_l(n);
    std::vector<int> prefix_r(n);
    prefix_l[0] = rain_l[0];
    prefix_r[0] = rain_r[0];
    for (int i = 1; i < n; ++i) {
        prefix_l[i] = prefix_l[i - 1] + rain_l[i];
        prefix_r[i] = prefix_r[i - 1] + rain_r[i];
    }

    std::vector<int> suffix_l(n);
    std::vector<int> suffix_r(n);
    suffix_l[n - 1] = rain_l[n - 1];
    suffix_r[n - 1] = rain_r[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        suffix_l[i] = suffix_l[i + 1] + rain_l[i];
        suffix_r[i] = suffix_r[i + 1] + rain_r[i];
    }

    int min_rain = std::min(prefix_l[n - 1], prefix_r[n - 1]);

    for (int k = 0; k < n; ++k) {
        int rain_before_l = (k == 0) ? 0 : prefix_l[k - 1];
        int rain_after_r = suffix_r[k];
        min_rain = std::min(min_rain, rain_before_l + 1 + rain_after_r);

        int rain_before_r = (k == 0) ? 0 : prefix_r[k - 1];
        int rain_after_l = suffix_l[k];
        min_rain = std::min(min_rain, rain_before_r + 1 + rain_after_l);
    }

    std::cout << min_rain << std::endl;

    return 0;
}
