/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    array<array<double, 4>, 3> qtd{};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            if (!(cin >> qtd[i][j])) return 0;
        }
    }

    array<double, 4> preco{};
    for (int j = 0; j < 4; j++) {
        if (!(cin >> preco[j])) return 0;
    }

    cout << fixed << setprecision(0);
    cout << "Digite a quantidade de ingredientes em cada produto (ovo, farinha, acucar e carne):\n";
    cout << "Digite o preco de cada ingrediente (ovo, farinha, acucar e carne):\n";

    cout << fixed << setprecision(2);
    for (int i = 0; i < 3; i++) {
        double custo = 0.0;
        for (int j = 0; j < 4; j++) custo += qtd[i][j] * preco[j];
        string nome = (i == 0 ? "pastel" : (i == 1 ? "empada" : "kibe"));
        cout << "O custo do " << nome << " e R$ " << custo << ".\n";
    }

    return 0;
}