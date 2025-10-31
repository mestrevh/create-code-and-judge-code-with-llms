/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

double calcularSalario(float horas, float valorHora) {
    if (horas > 180) {
        float horasNormais = 180;
        float horasExtras = horas - 180;
        return (horasNormais * valorHora) + (horasExtras * valorHora * 1.5);
    } else {
        return horas * valorHora;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    float horas, valorHora;
    std::cin >> horas >> valorHora;
    std::cout << calcularSalario(horas, valorHora) << std::endl;
    return 0;
}
