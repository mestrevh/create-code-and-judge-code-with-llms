/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int N, J;
    while (cin >> N >> J, N || J) {
        vector<int> deck(N);
        for (int i = 0; i < N; ++i) {
            cin >> deck[i];
        }

        vector<stack<int>> players(J);
        vector<int> discard;
        int currentPlayer = 0;

        for (int i = 0; i < N; ++i) {
            int card = deck[i];
            bool turnContinues = true;

            while (turnContinues) {
                turnContinues = false;

                if (find(discard.begin(), discard.end(), card) != discard.end()) {
                    discard.erase(remove(discard.begin(), discard.end(), card), discard.end());
                    players[currentPlayer].push(card);
                    turnContinues = true;
                } else if (!players[currentPlayer].empty() && players[currentPlayer].top() == card) {
                    players[currentPlayer].push(card);
                    turnContinues = true;
                } else {
                    int nextPlayer = (currentPlayer + 1) % J;
                    if (!players[nextPlayer].empty() && players[nextPlayer].top() == card) {
                        stack<int> stolen;
                        while (!players[nextPlayer].empty()) {
                            stolen.push(players[nextPlayer].top());
                            players[nextPlayer].pop();
                        }
                        while (!stolen.empty()) {
                            players[currentPlayer].push(stolen.top());
                            stolen.pop();
                        }
                        players[currentPlayer].push(card);
                        turnContinues = true;
                    } else {
                        discard.push_back(card);
                    }
                }
                if (turnContinues) {
                    i++;
                    if (i < N) card = deck[i];
                }
            }

            currentPlayer = (currentPlayer + 1) % J;
            if (i >= N) break;
        }

        int maxCards = 0;
        for (int i = 0; i < J; ++i) {
            maxCards = max(maxCards, (int)players[i].size());
        }

        vector<int> winners;
        for (int i = 0; i < J; ++i) {
            if (players[i].size() == maxCards) {
                winners.push_back(i + 1);
            }
        }

        cout << maxCards << " ";
        for (size_t i = 0; i < winners.size(); ++i) {
            cout << winners[i];

            if (i < winners.size() - 1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}
