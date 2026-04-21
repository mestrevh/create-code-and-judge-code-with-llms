/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <set>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::set<int> set1;
    for (int i = 0; i < 20; ++i) {
        int val;
        if (std::cin >> val) {
            set1.insert(val);
        }
    }

    std::set<int> set2;
    for (int i = 0; i < 20; ++i) {
        int val;
        if (std::cin >> val) {
            set2.insert(val);
        }
    }

    bool printed = false;
    for (const int& x : set1) {
        if (set2.find(x) != set2.end()) {
            std::cout << x << "\n";
            printed = true;
        }
    }

    if (!printed) {
        std::cout << "VAZIO" << std::endl;
    }

    return 0;
}