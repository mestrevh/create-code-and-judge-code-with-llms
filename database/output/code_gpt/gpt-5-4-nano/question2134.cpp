/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    if (n <= 0 || n > 5) {
        cout << "Numero de notas invalido.";
        return 0;
    }

    vector<double> notas;
    notas.reserve(n);
    for (int i = 0; i < n; i++) {
        double x;
        cin >> x;
        notas.push_back(x);
    }

    cout.setf(std::ios::fixed);
    cout << setprecision(1);
    for (int i = 0; i < n; i++) {
        cout << "Nota " << (i + 1) << ": " << notas[i] << "\n";
    }

    double soma = 0.0;
    for (double x : notas) soma += x;
    double media = soma / n;

    cout << "Media: " << setprecision(2) << media;
    return 0;
}