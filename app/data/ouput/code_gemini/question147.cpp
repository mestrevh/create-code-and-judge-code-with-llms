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

    std::vector<int> casas(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> casas[i];
    }

    int k;
    std::cin >> k;

    int left = 0;
    int right = n - 1;

    while (left < right) {
        long long current_sum = (long long)casas[left] + casas[right];

        if (current_sum == k) {
            std::cout << casas[left] << " " << casas[right] << "\n";
            break;
        } else if (current_sum < k) {
            left++;
        } else {
            right--;
        }
    }

    return 0;
}
