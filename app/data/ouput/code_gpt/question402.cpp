/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
using namespace std;

string EstacaoAno(int dia, int mes) {
    if ((mes == 9 && dia >= 21) || (mes == 10) || (mes == 11) || (mes == 12 && dia <= 20)) {
        return "PRIMAVERA";
    } else if ((mes == 12 && dia >= 21) || (mes == 1) || (mes == 2) || (mes == 3 && dia <= 20)) {
        return "VERAO";
    } else if ((mes == 3 && dia >= 21) || (mes == 4) || (mes == 5) || (mes == 6 && dia <= 20)) {
        return "OUTONO";
    } else {
        return "INVERNO";
    }
}

int main() {
    int dia, mes;
    cin >> dia >> mes;
    cout << EstacaoAno(dia, mes) << endl;
    return 0;
}
