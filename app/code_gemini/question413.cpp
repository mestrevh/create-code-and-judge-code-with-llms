/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    while (std::cin >> n && n != 0) {
        std::queue<int> deck;
        for (int i = 1; i <= n; ++i) {
            deck.push(i);
        }

        std::vector<int> discarded_cards;
        while (deck.size() > 1) {
            discarded_cards.push_back(deck.front());
            deck.pop();
            
            deck.push(deck.front());
            deck.pop();
        }

        std::cout << "Discarded cards:";
        if (!discarded_cards.empty()) {
            std::cout << " " << discarded_cards[0];
            for (size_t i = 1; i < discarded_cards.size(); ++i) {
                std::cout << ", " << discarded_cards[i];
            }
        }
        std::cout << std::endl;

        std::cout << "Remaining card: " << deck.front() << std::endl;
    }

    return 0;
}
