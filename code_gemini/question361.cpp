/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>
#include <limits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    int min_labels = std::numeric_limits<int>::max();
    int current_labels;

    for (int i = 0; i < n; ++i) {
        std::cin >> current_labels;
        min_labels = std::min(min_labels, current_labels);
    }

    std::cout << min_labels << std::endl;

    return 0;
}
