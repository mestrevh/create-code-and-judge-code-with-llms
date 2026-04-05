/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    cout << "Digite o valor inteiro: ";
    if (!(cin >> N)) return 0;

    vector<long long> notes = {100, 50, 20, 10, 5, 2, 1};
    vector<string> labels = {
        "nota(s) de R$ 100,00",
        "nota(s) de R$ 50,00",
        "nota(s) de R$ 20,00",
        "nota(s) de R$ 10,00",
        "nota(s) de R$ 5,00",
        "nota(s) de R$ 2,00",
        "moeda(s) de R$ 1,00"
    };

    cout << "\n";
    long long remaining = N;
    for (int i = 0; i < 7; i++) {
        long long c = remaining / notes[i];
        remaining %= notes[i];
        cout << c << " " << labels[i] << "\n";
    }

    return 0;
}