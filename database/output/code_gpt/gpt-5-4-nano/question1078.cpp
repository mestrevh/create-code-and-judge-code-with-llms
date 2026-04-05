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

    bool valid = (0 <= a && a <= 100) && (0 <= b && b <= 100) && (0 <= c && c <= 100);
    cout.setf(ios::fixed);
    cout << setprecision(2);

    if (!valid) {
        cout << "Media invalida";
        return 0;
    }

    double media = (a + b + c) / 3.0;

    string situacao;
    if (media >= 70.0 && media <= 100.0) situacao = "APROVADO";
    else if (media >= 0.0 && media <= 40.0) situacao = "REPROVADO";
    else if (media > 40.0 && media < 70.0) situacao = "FINAL";
    else situacao = "INVALIDA";

    if (situacao == "INVALIDA") {
        cout << "Media invalida";
    } else {
        cout << "A media do aluno foi " << media << " e ele foi " << situacao;
    }

    return 0;
}