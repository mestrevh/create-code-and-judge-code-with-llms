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

    string n1, n2;
    while (getline(cin >> ws, n1)) {
        if (!getline(cin, n2)) break;
        int e1, e2;
        string c1, c2;
        double p1, p2;
        if (!(cin >> e1 >> e2 >> c1 >> c2 >> p1 >> p2)) break;

        int win = 0;
        if (e1 > e2) {
            win = 1;
        } else if (e2 > e1) {
            win = 2;
        } else {
            int b1 = (c1 == "Sim" ? 1 : 0);
            int b2 = (c2 == "Sim" ? 1 : 0);
            if (b1 > b2) {
                win = 1;
            } else if (b2 > b1) {
                win = 2;
            } else {
                if (p1 < p2) {
                    win = 1;
                } else if (p2 < p1) {
                    win = 2;
                } else {
                    win = 0;
                }
            }
        }

        if (win == 1) {
            cout << "O hotel " << n1 << " e a melhor opcao de estadia!\n";
        } else if (win == 2) {
            cout << "O hotel " << n2 << " e a melhor opcao de estadia!\n";
        } else {
            cout << "Ambos os hoteis sao boas opcoes de estadia!\n";
        }
    }

    return 0;
}