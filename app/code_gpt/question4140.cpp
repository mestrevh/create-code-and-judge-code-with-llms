/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    char solid, calc;
    cin >> solid >> calc;
    if (solid != 'c' && solid != 'e') {
        cout << "Entrada invalida! Voce deve usar 'c' (cilindro) ou 'e' (esfera)." << endl;
        return 0;
    }
    if (calc != 'a' && calc != 'v') {
        cout << "Entrada invalida! Entre com 'a' (area) ou 'v' (volume)." << endl;
        return 0;
    }

    const double PI = 3.1415;
    if (solid == 'e') {
        float radius;
        cin >> radius;
        if (calc == 'a') {
            double area = 4 * PI * radius * radius;
            cout << fixed << setprecision(2) << "A area da esfera de raio " << radius << " eh:\n" << area << endl;
        } else {
            double volume = (4.0 / 3.0) * PI * pow(radius, 3);
            cout << fixed << setprecision(2) << "O volume da esfera de raio " << radius << " eh:\n" << volume << endl;
        }
    } else {
        float radius, height;
        cin >> radius >> height;
        if (calc == 'a') {
            double area = 2 * PI * radius * (radius + height);
            cout << fixed << setprecision(2) << "A area do cilindro de raio " << radius << " e altura " << height << " eh:\n" << area << endl;
        } else {
            double volume = PI * radius * radius * height;
            cout << fixed << setprecision(2) << "O volume do cilindro de raio " << radius << " e altura " << height << " eh:\n" << volume << endl;
        }
    }
    return 0;
}
