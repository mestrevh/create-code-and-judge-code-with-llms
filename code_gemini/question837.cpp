/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::vector<int> speeds(5);
    for (int i = 0; i < 5; ++i) {
        std::cin >> speeds[i];
    }
    std::sort(speeds.begin(), speeds.end(), std::greater<int>());
    for (int i = 0; i < 5; ++i) {
        std::cout << i + 1 << " - " << speeds[i] << " km/h\n";
    }
    return 0;
}
