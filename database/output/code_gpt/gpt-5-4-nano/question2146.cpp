/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        char nat;
        if (!(cin >> nat)) return 0;
        if (nat != 'B' && nat != 'E') {
            cout << "Fim";
            return 0;
        }

        char occ;
        cin >> occ;
        int q;
        cin >> q;
        int c;
        if (cin >> c) {
        } else return 0;

        bool liberado = false;

        if (nat == 'E') {
            liberado = (q == 0);
        } else {
            if (occ == 'M') {
                liberado = true;
            } else if (occ == 'T' || occ == 'O') {
                liberado = (q == 1 && c <= 22);
            } else if (occ == 'C') {
                liberado = (q <= 2 && c <= 38);
            }
        }

        cout << (liberado ? "Liberado" : "Barrado");
        if (cin) {
            char next;
            if (!(cin >> ws)) return 0;
            streampos pos = cin.tellg();
            if (cin.peek() == EOF) return 0;
            if (!cin.good()) return 0;
            cin.seekg(pos);
            cout << "\n";
        }
    }
    return 0;
}