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

    const int SIZE = 20;
    std::set<int> set1;
    int num;

    for (int i = 0; i < SIZE; ++i) {
        std::cin >> num;
        set1.insert(num);
    }

    std::set<int> intersection;
    for (int i = 0; i < SIZE; ++i) {
        std::cin >> num;
        if (set1.count(num)) {
            intersection.insert(num);
        }
    }

    if (intersection.empty()) {
        std::cout << "VAZIO\n";
    } else {
        for (int val : intersection) {
            std::cout << val << "\n";
        }
    }

    return 0;
}
