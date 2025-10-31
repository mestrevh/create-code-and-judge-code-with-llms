/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <unordered_set>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::unordered_set<int> set_a;
    int element;
    for (int i = 0; i < n; ++i) {
        std::cin >> element;
        set_a.insert(element);
    }

    int m;
    std::cin >> m;

    bool is_subset = true;
    for (int i = 0; i < m; ++i) {
        std::cin >> element;
        if (set_a.count(element) == 0) {
            is_subset = false;
        }
    }

    if (is_subset) {
        std::cout << 1 << '\n';
    } else {
        std::cout << 0 << '\n';
    }

    return 0;
}
