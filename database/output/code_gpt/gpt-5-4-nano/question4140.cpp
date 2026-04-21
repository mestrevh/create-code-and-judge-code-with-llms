/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    char corpo, tipo;
    if (!(cin >> corpo)) return 0;
    if (!(cin >> tipo)) return 0;

    const double pi = 3.1415;

    cout.setf(std::ios::fixed);
    cout << setprecision(2);

    if (corpo != 'c' && corpo != 'e') {
        cout << "Entrada invalida! Voce deve usar 'c' (cilindro) ou 'e' (esfera).";
        return 0;
    }

    if (tipo != 'a' && tipo != 'v') {
        cout << "Entrada invalida! Entre com 'a' (area) ou 'v' (volume).";
        return 0;
    }

    if (corpo == 'e') {
        float raio;
        cin >> raio;
        double r = raio;

        if (tipo == 'a') {
            double area = 4.0 * pi * r * r;
            cout << "A area da esfera de raio " << r << " eh:\n" << area;
        } else {
            double vol = (4.0 / 3.0) * pi * r * r * r;
            cout << "O volume da esfera de raio " << r << " eh:\n" << vol;
        }
    } else {
        float raio, altura;
        cin >> raio >> altura;
        double r = raio, h = altura;

        if (tipo == 'a') {
            double area = 2.0 * pi * r * (r + h);
            cout << "A area da cilindro de raio " << r << " e altura " << h << " eh:\n" << area;
        } else {
            double vol = pi * r * r * h;
            cout << "O volume da cilindro de raio " << r << " e altura " << h << " eh:\n" << vol;
        }
    }

    return 0;
}