/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int m;
    std::cin >> m;

    std::set<int> set1;
    for (int i = 0; i < m; ++i) {
        int k;
        std::cin >> k;
        set1.insert(k);
    }

    std::set<int> intersection;
    for (int i = 0; i < m; ++i) {
        int k;
        std::cin >> k;
        if (set1.count(k)) {
            intersection.insert(k);
        }
    }

    bool first = true;
    for (int elem : intersection) {
        if (!first) {
            std::cout << " ";
        }
        std::cout << elem;
        first = false;
    }
    std::cout << std::endl;

    return 0;
}
