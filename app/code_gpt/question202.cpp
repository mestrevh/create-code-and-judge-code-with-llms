/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> seq(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> seq[i];
    }

    if (n <= 2) {
        std::cout << 1 << std::endl;
        return 0;
    }

    int parts = 1, diff = seq[1] - seq[0];
    for (int i = 1; i < n - 1; ++i) {
        if (seq[i + 1] - seq[i] != diff) {
            ++parts;
            diff = seq[i + 1] - seq[i];
        }
    }

    std::cout << parts << std::endl;
    return 0;
}
