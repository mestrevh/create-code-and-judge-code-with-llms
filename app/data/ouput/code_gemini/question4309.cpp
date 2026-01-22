/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<char> letters;
    char c;

    while (std::cin >> c) {
        letters.push_back(c);
    }

    std::sort(letters.begin(), letters.end());

    if (!letters.empty()) {
        std::cout << letters[0];
        for (size_t i = 1; i < letters.size(); ++i) {
            std::cout << " " << letters[i];
        }
    }
    std::cout << '\n';

    return 0;
}
