/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int baseMenor, baseMaior, altura;
    cout << "Digite a base menor: ";
    if (!(cin >> baseMenor)) return 0;
    cout << "Digite a base maior: ";
    cin >> baseMaior;
    cout << "Digite a altura: ";
    cin >> altura;

    double area = (static_cast<double>(baseMenor) + static_cast<double>(baseMaior)) * static_cast<double>(altura) / 2.0;
    cout << "Area do trapezio: " << fixed << setprecision(6) << area << "\n";
    return 0;
}