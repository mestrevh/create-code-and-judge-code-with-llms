/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    char ch;
    if (!(cin >> ch)) return 0;

    double x;
    if (!(cin >> x)) return 0;

    double area = 0.0;
    string nome;

    if (x <= 0) {
        cout << "Entrada invalida!\n";
        return 0;
    }

    if (ch == 'C' || ch == 'c') {
        nome = "Circulo";
        area = 3.141 * x * x;
    } else if (ch == 'Q' || ch == 'q') {
        nome = "Quadrado";
        area = x * x;
    } else if (ch == 'T' || ch == 't') {
        nome = "Triangulo equiatero";
        area = (1.7 * x * x) / 4.0;
    } else {
        cout << "Entrada invalida!\n";
        return 0;
    }

    cout << fixed << setprecision(2) << area << "\n" << nome;
    return 0;
}