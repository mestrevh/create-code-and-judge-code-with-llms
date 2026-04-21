/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int reinaldo_wins = 0;
    int helena_wins = 0;
    int reinaldo_sum = 0;
    int helena_sum = 0;

    for (int i = 0; i < 5; ++i) {
        int r, h;
        if (!(cin >> r >> h)) break;
        reinaldo_sum += r;
        helena_sum += h;
        if (r > h) {
            reinaldo_wins++;
        } else if (h > r) {
            helena_wins++;
        }
    }

    if (reinaldo_wins > helena_wins) {
        cout << "REINALDO" << endl;
    } else if (helena_wins > reinaldo_wins) {
        cout << "HELENA" << endl;
    } else {
        if (reinaldo_sum > helena_sum) {
            cout << "REINALDO" << endl;
        } else if (helena_sum > reinaldo_sum) {
            cout << "HELENA" << endl;
        } else {
            cout << "EMPATE" << endl;
        }
    }

    return 0;
}