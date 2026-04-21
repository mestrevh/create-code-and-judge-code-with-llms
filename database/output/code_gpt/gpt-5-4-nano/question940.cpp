/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long codigo;
    while (cin >> codigo) {
        cout << "Informe o codigo do aluno: (0 para encerrar o programa)\n";
        if (codigo == 0) break;

        double n1, n2, n3;
        cout << "Informe a primeira nota do aluno:\n";
        cin >> n1;
        cout << "Informe a segunda nota do aluno:\n";
        cin >> n2;
        cout << "Informe a terceira nota do aluno:\n";
        cin >> n3;

        double media = (n1 + n2 + n3) / 3.0;
        cout << "Media do aluno: " << fixed << setprecision(2) << media << "\n";
    }
    return 0;
}