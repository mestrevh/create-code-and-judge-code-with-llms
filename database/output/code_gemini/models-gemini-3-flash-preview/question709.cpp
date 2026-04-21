/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Optimize standard I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, o;
    // Read n (board size), m (number of players), o (number of rounds)
    if (!(cin >> n >> m >> o)) return 0;

    // Read board configuration
    // The index i corresponds to house i (from 0 to n-1)
    vector<int> board(n);
    for (int i = 0; i < n; ++i) {
        if (!(cin >> board[i])) break;
    }

    // Initialize all m players' positions at house 0
    vector<int> players(m, 0);

    // Process rounds and player turns
    // The input provides rolls in blocks per round
    for (int i = 0; i < o; ++i) {
        for (int j = 0; j < m; ++j) {
            int roll;
            if (!(cin >> roll)) break;
            
            // Move 1: Advance by the value of the die roll (v)
            // Die rolls are positive (1 to 6), so (pos + roll) % n is safe
            players[j] = (players[j] + roll) % n;
            
            // Move 2: Adjust position based on house effect (x)
            // The value at the landed house can be positive, negative, or zero
            int effect = board[players[j]];
            players[j] = (players[j] + effect) % n;
            
            // Handle circular array for backward moves (negative results of %)
            // In C++, the result of % has the same sign as the dividend.
            // If the position becomes negative, adding n wraps it correctly.
            if (players[j] < 0) {
                players[j] += n;
            }
        }
    }

    // Output final positions of players 1 to m
    for (int i = 0; i < m; ++i) {
        cout << players[i] << "\n";
    }

    return 0;
}