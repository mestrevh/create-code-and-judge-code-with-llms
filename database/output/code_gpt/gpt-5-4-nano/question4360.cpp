/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    double nota;
    if (!(cin >> nota)) return 0;

    cout << fixed << setprecision(1);
    cout << "Nota digitada: " << nota << "\n";
    if (nota < 0.0 || nota > 10.0) {
        cout << "A nota nao esta no intervalo [0,10]";
    }
    return 0;
}