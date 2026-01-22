/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

float calculaDelta(float a, float b, float c) {
    return b * b - 4 * a * c;
}

void calculaRaizes(float a, float b, float c, float *x1, float *x2) {
    float delta = calculaDelta(a, b, c);
    *x1 = (-b + sqrt(delta)) / (2 * a);
    *x2 = (-b - sqrt(delta)) / (2 * a);
}

int main() {
    float a, b, c, x1, x2;
    cin >> a >> b >> c;
    
    if (a == 0 || calculaDelta(a, b, c) < 0) {
        cout << "Digite os coeficientes da equacao:\nImpossivel calcular\n";
    } else {
        calculaRaizes(a, b, c, &x1, &x2);
        cout << "Digite os coeficientes da equacao:\n";
        cout << fixed << setprecision(5);
        cout << "X1 = " << x1 << "\nX2 = " << x2 << endl;
    }
    return 0;
}
