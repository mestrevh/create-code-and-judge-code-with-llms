/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double a, b, c, d;
    if (!(cin >> a)) return 0;
    cin >> b >> c >> d;

    double media = (a + b + c + d) / 4.0;

    cout << "Informe a primeira nota do aluno:\n";
    cout << "Informe a segunda nota do aluno:\n";
    cout << "Informe a terceira nota do aluno:\n";
    cout << "Informe a quarta nota do aluno:\n";
    cout << "Media: " << fixed << setprecision(3) << media;
    return 0;
}