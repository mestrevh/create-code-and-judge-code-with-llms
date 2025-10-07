/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <queue>
#include <vector>

int main() {
    int n;
    while (std::cin >> n && n != 0) {
        std::queue<int> cards;
        for (int i = 1; i <= n; ++i) {
            cards.push(i);
        }

        std::vector<int> discarded;
        while (cards.size() > 1) {
            discarded.push_back(cards.front());
            cards.pop();
            cards.push(cards.front());
            cards.pop();
        }

        std::cout << "Discarded cards: ";
        for (size_t i = 0; i < discarded.size(); ++i) {
            if (i > 0) std::cout << ", ";
            std::cout << discarded[i];
        }
        std::cout << "\nRemaining card: " << cards.front() << "\n";
    }
    return 0;
}
