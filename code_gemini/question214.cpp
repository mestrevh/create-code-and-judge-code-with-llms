/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    long long total_sum = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        total_sum += a[i];
    }
    long long half_sum = total_sum / 2;
    long long current_sum = 0;
    for (int i = 0; i < n; ++i) {
        current_sum += a[i];
        if (current_sum == half_sum) {
            std::cout << i + 1 << std::endl;
            break;
        }
    }
    return 0;
}
