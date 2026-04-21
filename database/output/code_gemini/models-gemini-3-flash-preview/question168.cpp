/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double ingredients[3][4];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (!(cin >> ingredients[i][j])) break;
        }
    }

    double prices[4];
    for (int i = 0; i < 4; ++i) {
        if (!(cin >> prices[i])) break;
    }

    cout << fixed << setprecision(2);
    for (int i = 0; i < 3; ++i) {
        double cost = 0.0;
        for (int j = 0; j < 4; ++j) {
            cost += ingredients[i][j] * prices[j];
        }
        cout << cost << "\n";
    }

    return 0;
}

