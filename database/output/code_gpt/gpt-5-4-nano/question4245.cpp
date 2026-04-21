/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Caixa {
    long long largura, profundidade, altura;
    long long volume() const {
        return largura * profundidade * altura;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<Caixa> caixas(n);
    for (int i = 0; i < n; i++) {
        cin >> caixas[i].largura >> caixas[i].profundidade >> caixas[i].altura;
    }

    bool printed = false;
    for (const auto& c : caixas) {
        if (c.altura <= 10) {
            cout << c.volume() << "\n";
            printed = true;
        }
    }

    if (!printed) cout << " Nenhuma caixa passa pelo tunel! ";
    return 0;
}