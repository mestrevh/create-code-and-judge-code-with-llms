/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int mes;
    cin >> mes;
    
    if (mes < 1 || mes > 12) {
        cout << "Voce entrou com um mes invalido!" << endl;
    } else {
        int dias;
        if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) {
            dias = 31;
        } else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
            dias = 30;
        } else {
            dias = 28;
        }
        cout << "Numero de dias do mes " << mes << " : " << dias << " dias" << endl;
    }
    return 0;
}
