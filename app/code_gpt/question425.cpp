/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    while (true) {
        int N;
        cin >> N;
        if (N == 0) break;

        vector<string> players(N);
        for (int i = 0; i < N; ++i) {
            cin >> players[i];
        }

        queue<int> deck;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 13; ++j) {
                int card;
                cin >> card;
                deck.push(card);
            }
        }

        vector<bool> active(N, true);
        int remaining = N;

        while (remaining > 1 && !deck.empty()) {
            vector<int> cards(N, 0);
            vector<int> round_winners;
            int min_card = 14;

            for (int i = 0; i < N; ++i) {
                if (active[i]) {
                    if (!deck.empty()) {
                        cards[i] = deck.front();
                        deck.pop();
                        if (cards[i] < min_card) {
                            min_card = cards[i];
                            round_winners = {i};
                        } else if (cards[i] == min_card) {
                            round_winners.push_back(i);
                        }
                    }
                }
            }

            for (int idx : round_winners) {
                active[idx] = false;
                remaining--;
            }
        }

        vector<string> winners;
        for (int i = 0; i < N; ++i) {
            if (active[i]) {
                winners.push_back(players[i]);
            }
        }

        cout << winners[0];
        for (size_t i = 1; i < winners.size(); ++i) {
            cout << " " << winners[i];
        }
        cout << endl;
    }
    return 0;
}
