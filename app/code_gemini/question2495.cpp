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

    if (n <= 1) {
        std::cout << 0 << std::endl;
        return 0;
    }

    std::vector<int> statues(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> statues[i];
    }

    std::sort(statues.begin(), statues.end());

    int min_val = statues.front();
    int max_val = statues.back();

    int needed = (max_val - min_val + 1) - n;

    std::cout << needed << std::endl;

    return 0;
}
