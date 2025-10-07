/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> coins(n);
    int total = 0;

    for (int i = 0; i < n; ++i) {
        std::cin >> coins[i];
        total += coins[i];
    }

    std::sort(coins.rbegin(), coins.rend());

    int brother_sum = 0;
    int twin_sum = 0;
    int count = 0;

    for (int coin : coins) {
        twin_sum += coin;
        count++;
        if (twin_sum > (total - twin_sum)) {
            break;
        }
    }

    std::cout << count << std::endl;
    return 0;
}
