/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Jogo {
    int nota;
    double preco;
};

bool compararJogos(const Jogo& a, const Jogo& b) {
    if (a.nota != b.nota) {
        return a.nota > b.nota;
    }
    return a.preco < b.preco;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<Jogo> jogos(n);
    for (int i = 0; i < n; i++) {
        cin >> jogos[i].nota >> jogos[i].preco;
    }

    sort(jogos.begin(), jogos.end(), compararJogos);

    for (int i = 0; i < n; i++) {
        cout << "Nota: " << jogos[i].nota << "\n";
        cout << "Preco: " << fixed << setprecision(2) << jogos[i].preco << "\n";
        if (i < n - 1) {
            cout << "\n";
        }
    }

    return 0;
}