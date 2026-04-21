/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double baseMaior, baseMenor, altura;
    cout << "Digite o valor da base maior: ";
    if (!(cin >> baseMaior)) return 0;
    cout << "Digite o valor da base menor: ";
    cin >> baseMenor;
    cout << "Digite o valor da altura: ";
    cin >> altura;

    double area = (baseMaior + baseMenor) * altura / 2.0;
    long long parteInteira = (long long)floor(area);

    cout << "A parte inteira da área equivale a: " << parteInteira;
    return 0;
}