/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int a, b;
    while (std::cin >> a >> b && (a != 0 || b != 0)) {
        std::set<int> set_a;
        int card;
        for (int i = 0; i < a; ++i) {
            std::cin >> card;
            set_a.insert(card);
        }

        std::set<int> set_b;
        for (int i = 0; i < b; ++i) {
            std::cin >> card;
            set_b.insert(card);
        }

        int common_count = 0;
        
        if (set_a.size() < set_b.size()) {
            for (const auto& c : set_a) {
                if (set_b.count(c)) {
                    common_count++;
                }
            }
        } else {
            for (const auto& c : set_b) {
                if (set_a.count(c)) {
                    common_count++;
                }
            }
        }

        int tradeable_a = set_a.size() - common_count;
        int tradeable_b = set_b.size() - common_count;

        std::cout << std::min(tradeable_a, tradeable_b) << std::endl;
    }

    return 0;
}
