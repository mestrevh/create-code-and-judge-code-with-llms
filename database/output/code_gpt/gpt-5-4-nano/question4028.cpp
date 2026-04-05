/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    if (!(cin >> n)) return 0;

    int tonica = (n / 100) % 7;
    int terça = (n / 10) % 7;
    int quinta = n % 7;

    vector<string> nomes = {"do", "re", "mi", "fa", "sol", "la", "si"};

    vector<array<int,3>> acordeVal = {
        {0, 2, 4},
        {1, 3, 5},
        {2, 4, 6},
        {3, 5, 0},
        {4, 6, 1},
        {5, 0, 2},
        {6, 1, 3}
    };

    string resultado;
    bool ok = false;
    for (int i = 0; i < 7; i++) {
        if (acordeVal[i][0] == tonica && acordeVal[i][1] == terça && acordeVal[i][2] == quinta) {
            resultado = nomes[i];
            ok = true;
            break;
        }
    }

    if (ok) cout << "Acorde " << resultado << " satisfaz.\n";
    else cout << "Combinacao nao satisfaz.\n";

    return 0;
}