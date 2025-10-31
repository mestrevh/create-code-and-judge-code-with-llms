/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, k;
    while (std::cin >> n >> k) {
        std::vector<int> grades(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> grades[i];
        }
        std::sort(grades.rbegin(), grades.rend());
        long long sum = 0;
        for (int i = 0; i < k; ++i) {
            sum += grades[i];
        }
        std::cout << sum << "\n";
    }
    return 0;
}
