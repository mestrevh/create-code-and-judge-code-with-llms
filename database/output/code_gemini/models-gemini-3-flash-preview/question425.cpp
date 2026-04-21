/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    while (cin >> N && N != 0) {
        vector<string> names(N);
        for (int i = 0; i < N; ++i) {
            cin >> names[i];
        }

        deque<int> deck;
        for (int i = 0; i < 52; ++i) {
            int card_val;
            cin >> card_val;
            deck.push_back(card_val);
        }

        vector<int> active_indices;
        for (int i = 0; i < N; ++i) {
            active_indices.push_back(i);
        }

        while (active_indices.size() > 1) {
            if (deck.size() < active_indices.size()) {
                // If deck runs out before the round completes, 
                // everyone active at the start of the round wins.
                break;
            }

            int min_card = 14;
            vector<int> cards_drawn;
            for (size_t i = 0; i < active_indices.size(); ++i) {
                int drawn = deck.front();
                deck.pop_front();
                cards_drawn.push_back(drawn);
                if (drawn < min_card) {
                    min_card = drawn;
                }
            }

            vector<int> survivors;
            for (size_t i = 0; i < active_indices.size(); ++i) {
                if (cards_drawn[i] != min_card) {
                    survivors.push_back(active_indices[i]);
                }
            }

            if (survivors.empty()) {
                // If everyone drew the minimum card, they all win.
                break;
            }

            active_indices = survivors;
        }

        for (size_t i = 0; i < active_indices.size(); ++i) {
            if (i > 0) cout << " ";
            cout << names[active_indices[i]];
        }
        cout << "\n";
    }

    return 0;
}