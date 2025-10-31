/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

bool ehBissexto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

int diasNoMes(int mes, int ano) {
    if (mes == 2) return ehBissexto(ano) ? 29 : 28;
    if (mes == 4 || mes == 6 || mes == 9 || mes == 11) return 30;
    return 31;
}

void calcularNovaData(int dia, int mes, int ano, int dias) {
    dia += dias;
    while (true) {
        int diasDoMes = diasNoMes(mes, ano);
        if (dia > diasDoMes) {
            dia -= diasDoMes;
            mes++;
            if (mes > 12) {
                mes = 1;
                ano++;
            }
        } else {
            break;
        }
    }
    cout << setw(2) << setfill('0') << dia << "/"
         << setw(2) << setfill('0') << mes << "/"
         << ano << endl;
}

int main() {
    string data;
    int dias;

    cin >> data >> dias;
    int dia, mes, ano;
    char separador;

    stringstream(data) >> dia >> separador >> mes >> separador >> ano;
    calcularNovaData(dia, mes, ano, dias);
    
    return 0;
}
