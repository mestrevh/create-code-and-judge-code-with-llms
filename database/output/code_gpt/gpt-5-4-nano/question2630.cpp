/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double a, b, c;
    cout << "Digite o valor do primeiro ângulo:\n";
    if (!(cin >> a)) return 0;
    cout << "Digite o valor do segundo ângulo:\n";
    cin >> b;
    cout << "Digite o valor do terceiro ângulo:\n";
    cin >> c;

    string resp;
    if (a == 90 || b == 90 || c == 90) resp = "Este e um triangulo retangulo.";
    else if (a > 90 || b > 90 || c > 90) resp = "Este e um triangulo obtusangulo.";
    else resp = "Este e um triangulo acutangulo.";

    cout << resp << "\n";
    return 0;
}