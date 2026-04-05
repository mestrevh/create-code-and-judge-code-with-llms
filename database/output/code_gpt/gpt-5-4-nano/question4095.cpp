/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

float calculaDelta(float a, float b, float c) {
    return b * b - 4.0f * a * c;
}

void calculaRaizes(float a, float b, float c, float *x1, float *x2) {
    float delta = calculaDelta(a, b, c);
    float sqrtDelta = sqrt(delta);
    *x1 = (-b + sqrtDelta) / (2.0f * a);
    *x2 = (-b - sqrtDelta) / (2.0f * a);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    float a, b, c;
    if (!(cin >> a >> b >> c)) return 0;

    cout << fixed << setprecision(5);

    if (a == 0.0f) {
        cout << "Digite os coeficientes da equacao:\n";
        cout << "Impossivel calcular\n";
        return 0;
    }

    float delta = calculaDelta(a, b, c);
    if (delta < 0.0f) {
        cout << "Digite os coeficientes da equacao:\n";
        cout << "Impossivel calcular\n";
        return 0;
    }

    if (2.0f * a == 0.0f) {
        cout << "Digite os coeficientes da equacao:\n";
        cout << "Impossivel calcular\n";
        return 0;
    }

    float x1, x2;
    calculaRaizes(a, b, c, &x1, &x2);

    cout << "Digite os coeficientes da equacao:\n";
    cout << "X1 = " << x1 << "\n";
    cout << "X2 = " << x2 << "\n";
    return 0;
}