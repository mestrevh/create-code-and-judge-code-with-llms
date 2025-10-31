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
    std::vector<int> costs(3);
    std::cin >> costs[0] >> costs[1] >> costs[2];
    std::sort(costs.begin(), costs.end());
    int evolved_count = 0;
    for (int cost : costs) {
        if (n >= cost) {
            n -= cost;
            evolved_count++;
        } else {
            break;
        }
    }
    std::cout << evolved_count << std::endl;
    return 0;
}
