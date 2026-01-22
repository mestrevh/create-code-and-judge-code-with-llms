/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <deque>
#include <sstream>

int get_card_value(char rank) {
    if (rank >= '2' && rank <= '9') return rank - '0';
    if (rank == 'T') return 10;
    if (rank == 'J') return 11;
    if (rank == 'Q') return 12;
    if (rank == 'K') return 13;
    if (rank == 'A') return 14;
    return 0;
}

void solve() {
    std::deque<int> p1_deck;
    std::string line;
    std::getline(std::cin, line);
    std::stringstream ss1(line);
    std::string card_str;
    while (ss1 >> card_str) {
        if (!card_str.empty()) {
            p1_deck.push_back(get_card_value(card_str[0]));
        }
    }

    std::deque<int> p2_deck;
    std::getline(std::cin, line);
    std::stringstream ss2(line);
    while (ss2 >> card_str) {
        if (!card_str.empty()) {
            p2_deck.push_back(get_card_value(card_str[0]));
        }
    }

    int jogadas = 0;
    const int MAX_JOGADAS = 100000;

    while (true) {
        if (p1_deck.empty()) {
            std::cout << "jogador 2 ganhou com " << jogadas << " passos.\n";
            return;
        }
        if (p2_deck.empty()) {
            std::cout << "jogador 1 ganhou com " << jogadas << " passos.\n";
            return;
        }
        if (jogadas >= MAX_JOGADAS) {
            std::cout << "jogo empatado apos 100000 jogadas. Jogador 1 |" << p1_deck.size()
                      << "| cartas e jogador 2 |" << p2_deck.size() << "| cartas.\n";
            return;
        }

        jogadas++;

        int c1 = p1_deck.front();
        p1_deck.pop_front();
        int c2 = p2_deck.front();
        p2_deck.pop_front();

        std::deque<int> table1, table2;
        table1.push_back(c1);
        table2.push_back(c2);

        while (c1 == c2) {
            if (p1_deck.empty()) {
                std::cout << "jogador 2 ganhou com " << jogadas << " passos.\n";
                return;
            }
            table1.push_back(p1_deck.front());
            p1_deck.pop_front();

            if (p2_deck.empty()) {
                std::cout << "jogador 1 ganhou com " << jogadas << " passos.\n";
                return;
            }
            table2.push_back(p2_deck.front());
            p2_deck.pop_front();
            
            if (p1_deck.empty()) {
                std::cout << "jogador 2 ganhou com " << jogadas << " passos.\n";
                return;
            }
            if (p2_deck.empty()) {
                std::cout << "jogador 1 ganhou com " << jogadas << " passos.\n";
                return;
            }

            if (jogadas >= MAX_JOGADAS) {
                 break; 
            }

            jogadas++;
            c1 = p1_deck.front();
            p1_deck.pop_front();
            c2 = p2_deck.front();
            p2_deck.pop_front();

            table1.push_back(c1);
            table2.push_back(c2);
        }

        if (c1 == c2) {
            continue;
        }

        if (c1 > c2) {
            for (int card : table1) p1_deck.push_back(card);
            for (int card : table2) p1_deck.push_back(card);
        } else {
            for (int card : table1) p2_deck.push_back(card);
            for (int card : table2) p2_deck.push_back(card);
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    std::string dummy;
    std::getline(std::cin, dummy); 

    while (n--) {
        solve();
    }

    return 0;
}
