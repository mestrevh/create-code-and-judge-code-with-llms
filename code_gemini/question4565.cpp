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

    int o;
    std::cin >> o;

    int n;
    std::cin >> n;
    std::set<int> p1_stickers;
    for (int i = 0; i < n; ++i) {
        int fig;
        std::cin >> fig;
        p1_stickers.insert(fig);
    }

    int m;
    std::cin >> m;
    std::vector<int> p2_stickers(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> p2_stickers[i];
    }

    if (o == 1) {
        for (int sticker : p2_stickers) {
            p1_stickers.insert(sticker);
        }
        
        if (p1_stickers.empty()) {
            std::cout << "empty\n";
        } else {
            bool first = true;
            for (int sticker : p1_stickers) {
                if (!first) {
                    std::cout << " ";
                }
                std::cout << sticker;
                first = false;
            }
            std::cout << "\n";
        }
    } else { // o == 2
        std::set<int> intersection;
        for (int sticker : p2_stickers) {
            if (p1_stickers.count(sticker)) {
                intersection.insert(sticker);
            }
        }
        
        if (intersection.empty()) {
            std::cout << "empty\n";
        } else {
            bool first = true;
            for (int sticker : intersection) {
                if (!first) {
                    std::cout << " ";
                }
                std::cout << sticker;
                first = false;
            }
            std::cout << "\n";
        }
    }

    return 0;
}
