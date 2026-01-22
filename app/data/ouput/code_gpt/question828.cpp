/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    double ganho_por_hora, horas_trabalhadas, salario;
    cout << "Informe quanto ganha por hora:" << endl;
    cin >> ganho_por_hora;
    cout << "Informe a quantidade mensal de trabalho:" << endl;
    cin >> horas_trabalhadas;
    salario = ganho_por_hora * horas_trabalhadas;
    cout << "Resultado: " << salario << endl;
    return 0;
}
