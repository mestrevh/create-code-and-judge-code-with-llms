/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    double A, B, C;
    cout << "Digite o comprimento do lado A:\n";
    cin >> A;
    cout << "Digite o comprimento do lado B:\n";
    cin >> B;
    cout << "Digite o comprimento do lado C:\n";
    cin >> C;

    if (A == B && B == C) {
        cout << "Este e um triangulo equilatero.\n";
    } else if (A == B || B == C || A == C) {
        cout << "Este e um triangulo isosceles.\n";
    } else {
        cout << "Este e um triangulo escaleno.\n";
    }

    return 0;
}
