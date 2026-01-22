/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

struct Complexo {
    int real;
    int imag;
};

void imprimir(Complexo z) {
    std::cout << z.real;
    if (z.imag >= 0) {
        std::cout << "+";
    }
    std::cout << z.imag << "i";
}

Complexo soma(Complexo z1, Complexo z2) {
    Complexo resultado;
    resultado.real = z1.real + z2.real;
    resultado.imag = z1.imag + z2.imag;
    return resultado;
}

Complexo multiplicacao(Complexo z1, Complexo z2) {
    Complexo resultado;
    resultado.real = z1.real * z2.real - z1.imag * z2.imag;
    resultado.imag = z1.real * z2.imag + z1.imag * z2.real;
    return resultado;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    Complexo z1, z2;

    std::cin >> z1.real >> z1.imag;
    std::cin >> z2.real >> z2.imag;

    Complexo resultado_soma = soma(z1, z2);
    Complexo resultado_multi = multiplicacao(z1, z2);

    std::cout << "Soma: ";
    imprimir(resultado_soma);
    std::cout << std::endl;

    std::cout << "Multi: ";
    imprimir(resultado_multi);
    std::cout << std::endl;

    return 0;
}
