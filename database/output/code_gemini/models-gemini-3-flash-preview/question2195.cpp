/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char N, S;
    int I;
    double VI;

    if (!(cin >> N >> I >> S >> VI)) return 0;

    if (I <= 0 || I > 120) {
        cout << "idade invalida!" << endl;
        return 0;
    }

    if ((N == 'F' || N == 'C') && I < 21) {
        cout << "nao pode comprar" << endl;
        return 0;
    }

    double max_disc = 0.0;

    if (S == 'F') {
        max_disc = max(max_disc, 0.10);
    }

    if (N == 'B') {
        max_disc = max(max_disc, 0.50);
    } else if (N == 'A') {
        if (I >= 18) {
            if (S == 'F') {
                max_disc = max(max_disc, 0.20);
            }
        } else {
            max_disc = max(max_disc, 0.20);
        }
    } else if (N == 'F' || N == 'C') {
        if (I >= 21) {
            max_disc = max(max_disc, 0.30);
        }
    } else if (N == 'I' || N == 'R') {
        if (I < 16) {
            max_disc = max(max_disc, 0.40);
        } else {
            max_disc = max(max_disc, 0.30);
        }
    }

    double final_price = VI * (1.0 - max_disc);

    cout << "R$ " << fixed << setprecision(2) << final_price << endl;

    return 0;
}