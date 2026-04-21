/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    while ( (cin >> N) ) {
        if (N == 0) break;

        vector<string> names(N);
        for (int i = 0; i < N; i++) cin >> names[i];

        vector<int> deck;
        deck.reserve(52);
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 13; j++) {
                int x; 
                cin >> x;
                deck.push_back(x);
            }
        }

        vector<int> active(N, 1);
        int activeCount = N;

        size_t idx = 0;
        while (activeCount > 1 && idx < deck.size()) {
            vector<int> playersThisRound;
            playersThisRound.reserve(activeCount);
            for (int i = 0; i < N; i++) if (active[i]) playersThisRound.push_back(i);

            if (idx + playersThisRound.size() > deck.size()) break;

            int minCard = INT_MAX;
            vector<pair<int,int>> cardOf; 
            cardOf.reserve(playersThisRound.size());

            for (int k = 0; k < (int)playersThisRound.size(); k++) {
                int p = playersThisRound[k];
                int card = deck[idx++];
                cardOf.push_back({card, p});
                if (card < minCard) minCard = card;
            }

            vector<int> removed;
            for (auto &cp : cardOf) {
                if (cp.first == minCard) {
                    int p = cp.second;
                    if (active[p]) {
                        active[p] = 0;
                        activeCount--;
                    }
                }
            }
        }

        vector<string> winners;
        for (int i = 0; i < N; i++) if (active[i]) winners.push_back(names[i]);

        for (int i = 0; i < (int)winners.size(); i++) {
            if (i) cout << ' ';
            cout << winners[i];
        }
        cout << "\n";
    }
    return 0;
}