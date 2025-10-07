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

    std::vector<int> evens;
    std::vector<int> odds;

    for (int i = 0; i < n; ++i) {
        int val;
        std::cin >> val;
        if (val % 2 == 0) {
            evens.push_back(val);
        } else {
            odds.push_back(val);
        }
    }

    std::sort(evens.begin(), evens.end());
    std::sort(odds.rbegin(), odds.rend());

    for (int val : evens) {
        std::cout << val << "\n";
    }

    for (int val : odds) {
        std::cout << val << "\n";
    }

    return 0;
}
