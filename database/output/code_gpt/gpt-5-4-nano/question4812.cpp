/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

double calcularMediaFinal(const vector<double>& notas) {
    double soma = 0.0;
    for (double x : notas) soma += x;

    double min1 = numeric_limits<double>::infinity();
    double min2 = numeric_limits<double>::infinity();
    for (double x : notas) {
        if (x < min1) {
            min2 = min1;
            min1 = x;
        } else if (x < min2) {
            min2 = x;
        }
    }

    return (soma - min1 - min2) / (notas.size() - 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    vector<double> notas(N);
    for (int i = 0; i < N; i++) cin >> notas[i];

    if (N < 3) {
        cout << "Numero de notas insuficiente.";
        return 0;
    }

    double media = calcularMediaFinal(notas);
    cout << fixed << setprecision(2) << media;
    return 0;
}