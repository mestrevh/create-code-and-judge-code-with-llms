/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::map<char, int> counts;
    char c;

    for (int i = 0; i < 5; ++i) {
        std::cin >> c;
        counts[c]++;
    }

    int odd_counts = 0;
    for (auto const& pair : counts) {
        if (pair.second % 2 != 0) {
            odd_counts++;
        }
    }

    if (odd_counts <= 1) {
        std::cout << "sim\n";
    } else {
        std::cout << "nao\n";
    }

    return 0;
}
