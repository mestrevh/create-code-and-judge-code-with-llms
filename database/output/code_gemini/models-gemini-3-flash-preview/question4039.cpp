/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long k;
    if (!(cin >> n >> k)) return 0;

    long long actual_ships = 0;
    vector<int> board;
    if (n > 0) {
        board.assign((size_t)n * n, 0);
        for (int i = 0; i < n * n; ++i) {
            if (!(cin >> board[i])) break;
            if (board[i] == 1) {
                actual_ships++;
            }
        }
    }

    bool defense_invalid = (actual_ships > k);
    bool attack_invalid = false;
    long long ships_hit = 0;

    for (long long i = 0; i < 2 * k; ++i) {
        int r, c;
        if (!(cin >> r >> c)) break;
        if (r < 0 || r >= n || c < 0 || c >= n) {
            attack_invalid = true;
        } else if (!defense_invalid) {
            if (board[(size_t)r * n + c] == 1) {
                ships_hit++;
                board[(size_t)r * n + c] = 0;
            }
        }
    }

    if (defense_invalid) {
        cout << "Defesa invalida!" << endl;
    } else if (attack_invalid) {
        cout << "Ataque invalido!" << endl;
    } else {
        if (ships_hit == actual_ships) {
            cout << "Ataque venceu!" << endl;
        } else {
            cout << "Defesa venceu!" << endl;
        }
    }

    return 0;
}