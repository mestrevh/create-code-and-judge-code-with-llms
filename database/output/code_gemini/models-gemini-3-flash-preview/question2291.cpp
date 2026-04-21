/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m;
    if (!(cin >> m)) return 0;

    double v1, v2;
    if (!(cin >> v1 >> v2)) return 0;

    double ar = 0, dr = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            double val;
            cin >> val;
            if (i == j) ar += val;
            if (i + j == m - 1) dr += val;
        }
    }

    double ak = 0, dk = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            double val;
            cin >> val;
            if (i == j) ak += val;
            if (i + j == m - 1) dk += val;
        }
    }

    int n;
    if (!(cin >> n)) {
        if (v1 > v2) cout << "Ryu ganhou a batalha." << endl;
        else if (v2 > v1) cout << "Ken ganhou a batalha." << endl;
        else cout << "Houve empate." << endl;
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        string r_act, k_act;
        cin >> r_act >> k_act;

        if (r_act == "A" && k_act == "A") {
            if (ar > ak) {
                v2 -= (ar - ak);
            } else if (ak > ar) {
                v1 -= (ak - ar);
            }
        } else if (r_act == "A" && k_act == "D") {
            if (ar > dk) {
                v2 -= (ar - dk) / 2.0;
            }
        } else if (r_act == "D" && k_act == "A") {
            if (ak > dr) {
                v1 -= (ak - dr) / 2.0;
            }
        }
    }

    if (v1 > v2) {
        cout << "Ryu ganhou a batalha." << endl;
    } else if (v2 > v1) {
        cout << "Ken ganhou a batalha." << endl;
    } else {
        cout << "Houve empate." << endl;
    }

    return 0;
}