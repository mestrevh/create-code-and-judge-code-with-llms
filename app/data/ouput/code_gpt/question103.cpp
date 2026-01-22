/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <set>

int main() {
    int n;
    while (std::cin >> n) {
        std::vector<int> seq(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> seq[i];
        }
        if (n == 1) {
            std::cout << "Jolly" << std::endl;
            continue;
        }

        std::set<int> diffs;
        for (int i = 1; i < n; ++i) {
            diffs.insert(std::abs(seq[i] - seq[i - 1]));
        }

        bool jolly = true;
        for (int i = 1; i < n; ++i) {
            if (diffs.find(i) == diffs.end()) {
                jolly = false;
                break;
            }
        }
        
        std::cout << (jolly ? "Jolly" : "Not jolly") << std::endl;
    }
    return 0;
}
