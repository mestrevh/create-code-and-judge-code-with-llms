/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, J;
    while (cin >> N >> J && (N != 0 || J != 0)) {
        vector<int> stock(N);
        for (int i = 0; i < N; ++i) {
            cin >> stock[i];
        }

        vector<int> stack_size(J, 0);
        vector<int> top_card(J, -1);
        int discard[14] = {0};

        int currentPlayer = 0;
        int stockIndex = 0;

        while (stockIndex < N) {
            int card = stock[stockIndex++];
            bool matched = false;

            // Priority 1: Area de descarte
            if (discard[card] > 0) {
                stack_size[currentPlayer] += 2;
                top_card[currentPlayer] = card;
                discard[card]--;
                matched = true;
            } 
            // Priority 2: Topo de um monte
            else {
                int target = -1;
                // Rule states to check other players or own top.
                // Since only one player can have a certain value as their top, 
                // any matching k will be the unique target.
                for (int k = 0; k < J; ++k) {
                    if (stack_size[k] > 0 && top_card[k] == card) {
                        target = k;
                        break;
                    }
                }

                if (target != -1) {
                    if (target == currentPlayer) {
                        // Matching own stack
                        stack_size[currentPlayer] += 1;
                    } else {
                        // Stealing another stack
                        stack_size[currentPlayer] += (stack_size[target] + 1);
                        stack_size[target] = 0;
                        top_card[target] = -1;
                    }
                    top_card[currentPlayer] = card;
                    matched = true;
                }
            }

            // Only switch player if no match occurred
            if (!matched) {
                discard[card]++;
                currentPlayer = (currentPlayer + 1) % J;
            }
            // If matched == true, the player continues drawing (loop repeats with same currentPlayer)
        }

        // Calculate and output winners
        int max_size = 0;
        for (int i = 0; i < J; ++i) {
            if (stack_size[i] > max_size) {
                max_size = stack_size[i];
            }
        }

        cout << max_size;
        for (int i = 0; i < J; ++i) {
            if (stack_size[i] == max_size) {
                cout << " " << i + 1;
            }
        }
        cout << "\n";
    }

    return 0;
}