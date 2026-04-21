/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string nome1, nome2;
    if (!getline(cin, nome1)) return 0;
    getline(cin, nome2);

    int e1, e2;
    cin >> e1 >> e2;

    string c1, c2;
    cin >> c1 >> c2;

    double p1, p2;
    cin >> p1 >> p2;

    int stars1 = e1, stars2 = e2;
    bool breakfast1 = (c1 == "Sim");
    bool breakfast2 = (c2 == "Sim");

    bool win1 = false, win2 = false;

    if (stars1 > stars2) win1 = true;
    else if (stars2 > stars1) win2 = true;
    else {
        if (breakfast1 && !breakfast2) win1 = true;
        else if (breakfast2 && !breakfast1) win2 = true;
        else {
            const double eps = 1e-9;
            if (p1 + eps < p2) win1 = true;
            else if (p2 + eps < p1) win2 = true;
        }
    }

    if (win1 && !win2) {
        cout << "O hotel " << nome1 << " e a melhor opcao de estadia!";
    } else if (win2 && !win1) {
        cout << "O hotel " << nome2 << " e a melhor opcao de estadia!";
    } else {
        cout << "Ambos os hoteis sao boas opcoes de estadia!";
    }

    return 0;
}