/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c;
    if (!(cin >> a >> b >> c)) return 0;

    vector<pair<int,string>> v = {
        {a, "Introducao a Programacao"},
        {b, "Introducao a Computacao"},
        {c, "Calculo 6"}
    };

    sort(v.begin(), v.end(), [](const auto& x, const auto& y){
        return x.first > y.first;
    });

    int best = v[0].first;
    int cnt = 0;
    for (auto &p : v) if (p.first == best) cnt++;

    if (cnt != 1) {
        cout << "Empate.";
        return 0;
    }

    string winner = v[0].second;
    cout << "O vencedor é " << winner << " com um total de " << best << " votos.";
    if (winner == "Introducao a Programacao") cout << " E O HEXA VEIO.";
    return 0;
}