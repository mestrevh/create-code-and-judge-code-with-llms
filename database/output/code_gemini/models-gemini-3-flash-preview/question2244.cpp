/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        int winner = -1;
        for (int i = 1; i <= n; ++i) {
            int ticket;
            if (cin >> ticket) {
                if (ticket == i) {
                    winner = ticket;
                }
            }
        }
        if (winner != -1) {
            cout << "o ingresso de numero " << winner << " foi sorteado" << endl;
        }
    }

    return 0;
}