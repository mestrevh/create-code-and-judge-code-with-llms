/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << "Digite uma temperatura na escala Fahrenheit:\n";
    double F;
    if (!(cin >> F)) return 0;
    double C = (5.0 * (F - 32.0)) / 9.0;
    cout << "Temperatura em Celsius: " << fixed << setprecision(1) << C;
    return 0;
}