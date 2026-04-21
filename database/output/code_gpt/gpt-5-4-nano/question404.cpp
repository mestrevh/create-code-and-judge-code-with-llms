/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double media;
    long long faltas;
    if (!(cin >> media)) return 0;
    if (!(cin >> faltas)) return 0;

    const long long LIMITE_FALTAS = 10;

    string resp;
    if (faltas > LIMITE_FALTAS) {
        resp = "REPROVADO POR FALTAS";
    } else {
        if (media >= 9.5) resp = "APROVADO COM LOUVOR";
        else if (media >= 7.0) resp = "APROVADO";
        else resp = "REPROVADO";
    }

    cout << resp;
    return 0;
}