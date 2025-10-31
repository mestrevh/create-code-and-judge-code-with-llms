/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

int cardValue(const string& card) {
    char rank = card[0];
    if (rank == 'A') return 14;
    if (rank == 'K') return 13;
    if (rank == 'Q') return 12;
    if (rank == 'J') return 11;
    if (rank == 'T') return 10;
    return rank - '0'; // '2'-'0' -> 2, ... '9'-'0' -> 9
}

int main() {
    int n;
    cin >> n;

    while (n--) {
        queue<string> player1, player2;
        string card;
        for (int i = 0; i < 26; i++) {
            cin >> card;
            player1.push(card);
        }
        for (int i = 0; i < 26; i++) {
            cin >> card;
            player2.push(card);
        }

        int steps = 0;
        while (!player1.empty() && !player2.empty() && steps < 100000) {
            steps++;
            queue<string> warDeck;
            queue<string> table1, table2;

            table1.push(player1.front());
            player1.pop();
            table2.push(player2.front());
            player2.pop();

            while (cardValue(table1.back()) == cardValue(table2.back())) {
                if (player1.empty() || player2.empty()) break;

                warDeck.push(table1.back());
                warDeck.push(table2.back());
                table1.push(player1.front());
                player1.pop();
                table2.push(player2.front());
                player2.pop();
            }

            if (player1.empty() || player2.empty()) break;

            if (cardValue(table1.back()) > cardValue(table2.back())) {
                while (!table1.empty()) {
                    player1.push(table1.front());
                    table1.pop();
                }
                while (!table2.empty()) {
                    player1.push(table2.front());
                    table2.pop();
                }
                while (!warDeck.empty()) {
                    player1.push(warDeck.front());
                    warDeck.pop();
                }
            } else {
                while (!table1.empty()) {
                    player2.push(table1.front());
                    table1.pop();
                }
                while (!table2.empty()) {
                    player2.push(table2.front());
                    table2.pop();
                }
                while (!warDeck.empty()) {
                    player2.push(warDeck.front());
                    warDeck.pop();
                }
            }
        }

        if (steps >= 100000) {
            cout << "jogo empatado apos 100000 jogadas. Jogador 1 |" << player1.size() << "| cartas e jogador 2 |" << player2.size() << "| cartas" << endl;
        } else if (player1.empty()) {
            cout << "jogador 2 ganhou com " << steps << " passos." << endl;
        } else {
            cout << "jogador 1 ganhou com " << steps << " passos." << endl;
        }
    }
    return 0;
}
