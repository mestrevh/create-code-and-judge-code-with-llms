/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <stack>
#include <queue>

void solve() {
    int Q, P;
    std::cin >> Q >> P;

    std::vector<std::stack<int>> piles(P);
    for (int i = 0; i < P; ++i) {
        int pile_size;
        std::cin >> pile_size;
        for (int j = 0; j < pile_size; ++j) {
            int shirt;
            std::cin >> shirt;
            piles[i].push(shirt);
        }
    }

    std::queue<int> laundry;
    for (int k = 0; k < Q; ++k) {
        int type;
        std::cin >> type;
        if (type == 1) {
            int x;
            std::cin >> x;
            bool found = false;
            int shirt_found = -1;
            for (int i = 0; i < P; ++i) {
                if (!piles[i].empty()) {
                    int top_shirt = piles[i].top();
                    if (top_shirt >= x - 1 && top_shirt <= x + 1) {
                        shirt_found = top_shirt;
                        piles[i].pop();
                        laundry.push(shirt_found);
                        found = true;
                        break;
                    }
                }
            }
            if (found) {
                std::cout << shirt_found << "\n";
            } else {
                std::cout << "ze nao vai pra festa " << x << "\n";
            }
        } else {
            if (laundry.empty()) {
                std::cout << "nao tem roupa pra lavar\n";
            } else {
                laundry.pop();
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
