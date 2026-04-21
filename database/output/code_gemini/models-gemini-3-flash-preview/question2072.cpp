/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    int x = 0, y = 0;
    int current_side = 0; // 0: initial/wall, -1: kingdom y < x, 1: kingdom y > x
    int coins = 0;

    for (int i = 0; i < N; ++i) {
        char move;
        cin >> move;

        if (move == 'D') {
            x++;
        } else {
            y++;
        }

        if (x > y) {
            if (current_side == 1) {
                coins++;
            }
            current_side = -1;
        } else if (y > x) {
            if (current_side == -1) {
                coins++;
            }
            current_side = 1;
        }
        // If x == y, we don't update current_side yet, 
        // because we haven't crossed to a new kingdom.
    }

    cout << coins << endl;

    return 0;
}