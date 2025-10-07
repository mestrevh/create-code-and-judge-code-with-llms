/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long n;
    std::cin >> n;
    long long min_area = LLONG_MAX;
    for (long long l = 1; l * l * l <= n; ++l) {
        if (n % l == 0) {
            long long rem = n / l;
            for (long long w = l; w * w <= rem; ++w) {
                if (rem % w == 0) {
                    long long h = rem / w;
                    long long current_area = 2 * (l * w + w * h + h * l);
                    if (current_area < min_area) {
                        min_area = current_area;
                    }
                }
            }
        }
    }
    std::cout << min_area << std::endl;
    return 0;
}
