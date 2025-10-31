/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::string> recipes(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> recipes[i];
    }
    std::string ingredients_str;
    std::cin >> ingredients_str;

    int available[256] = {0};
    for (char c : ingredients_str) {
        available[static_cast<unsigned char>(c)]++;
    }

    for (const auto& recipe : recipes) {
        int needed[256] = {0};
        for (char c : recipe) {
            needed[static_cast<unsigned char>(c)]++;
        }

        int max_pizzas = std::numeric_limits<int>::max();
        if (recipe.empty()) {
            max_pizzas = 0;
        } else {
            for (int i = 0; i < 256; ++i) {
                if (needed[i] > 0) {
                    max_pizzas = std::min(max_pizzas, available[i] / needed[i]);
                }
            }
        }

        std::cout << max_pizzas << "\n";

        if (max_pizzas > 0) {
            for (int i = 0; i < 256; ++i) {
                if (needed[i] > 0) {
                    available[i] -= max_pizzas * needed[i];
                }
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    bool first_case = true;
    while (t--) {
        if (!first_case) {
            std::cout << "\n";
        }
        solve();
        first_case = false;
    }
    return 0;
}
