/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

struct Complexo {
    double real;
    double imaginario;
};

void imprimir(Complexo z) {
    cout << z.real << (z.imaginario >= 0 ? "+" : "") << z.imaginario << "i";
}

Complexo soma(Complexo z1, Complexo z2) {
    Complexo resultado;
    resultado.real = z1.real + z2.real;
    resultado.imaginario = z1.imaginario + z2.imaginario;
    return resultado;
}

Complexo multiplicacao(Complexo z1, Complexo z2) {
    Complexo resultado;
    resultado.real = z1.real * z2.real - z1.imaginario * z2.imaginario;
    resultado.imaginario = z1.real * z2.imaginario + z2.real * z1.imaginario;
    return resultado;
}

int main() {
    Complexo z1, z2;
    cin >> z1.real >> z1.imaginario;
    cin >> z2.real >> z2.imaginario;

    Complexo s = soma(z1, z2);
    Complexo m = multiplicacao(z1, z2);

    cout << "Soma: ";
    imprimir(s);
    cout << endl << "Multi: ";
    imprimir(m);
    cout << endl;

    return 0;
}
