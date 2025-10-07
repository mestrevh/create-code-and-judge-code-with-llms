/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

float calcularSalario(float horasTrabalhadas, float valorHora) {
    float salarioBase = horasTrabalhadas * valorHora;
    if (horasTrabalhadas > 180) {
        float horasExtras = horasTrabalhadas - 180;
        salarioBase += horasExtras * valorHora * 0.5;
    }
    return salarioBase;
}

int main() {
    float horas, valor;
    cin >> horas >> valor;
    cout << calcularSalario(horas, valor) << endl;
    return 0;
}
