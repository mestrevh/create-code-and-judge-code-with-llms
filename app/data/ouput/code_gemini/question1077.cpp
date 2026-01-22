/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <functional>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> coins(n);
    long long total_sum = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> coins[i];
        total_sum += coins[i];
    }

    std::sort(coins.begin(), coins.end(), std::greater<int>());

    long long my_sum = 0;
    int coins_taken = 0;
    long long target_sum = total_sum / 2;

    for (int coin_value : coins) {
        my_sum += coin_value;
        coins_taken++;
        if (my_sum > target_sum) {
            break;
        }
    }

    std::cout << coins_taken << std::endl;

    return 0;
}
