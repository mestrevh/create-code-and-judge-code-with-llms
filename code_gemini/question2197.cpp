/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<std::pair<int, char>> pieces(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> pieces[i].first >> pieces[i].second;
    }

    std::sort(pieces.begin(), pieces.end());

    for (int i = 0; i < n; ++i) {
        std::cout << pieces[i].second;
    }
    std::cout << '\n';

    return 0;
}
