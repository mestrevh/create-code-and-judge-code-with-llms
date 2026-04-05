/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double a, b, c, nulos;
    cout << "Digite a quantidade de votos do candidato A:\n";
    if (!(cin >> a)) return 0;
    cout << "Digite a quantidade de votos do candidato B:\n";
    cin >> b;
    cout << "Digite a quantidade de votos do candidato C:\n";
    cin >> c;
    cout << "Digite a quantidade de votos nulos:\n";
    cin >> nulos;

    double total = a + b + c + nulos;
    cout.setf(ios::fixed);
    cout << setprecision(6);

    if (total == 0) {
        cout << "Candidato A: 0 %\n";
        cout << "Candidato B: 0 %\n";
        cout << "Candidato C: 0 %\n";
        cout << "Votos Nulos: 0 %\n";
        return 0;
    }

    double pa = (a * 100.0) / total;
    double pb = (b * 100.0) / total;
    double pc = (c * 100.0) / total;
    double pn = (nulos * 100.0) / total;

    cout << "Candidato A: " << pa << " %\n";
    cout << "Candidato B: " << pb << " %\n";
    cout << "Candidato C: " << pc << " %\n";
    cout << "Votos Nulos: " << pn << " %\n";

    return 0;
}