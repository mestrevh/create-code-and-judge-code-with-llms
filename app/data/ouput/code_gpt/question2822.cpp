/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int sexo;
    double altura;

    cout << "Digite o sexo: (0 - M e 1 - F)" << endl;
    cin >> sexo;
    cout << "Digite a altura em metros:" << endl;
    cin >> altura;

    if (sexo != 0 && sexo != 1) {
        cout << "O sexo informado e invalido" << endl;
    } else if (altura <= 0) {
        cout << "Altura invalida" << endl;
    } else {
        double pesoIdeal;
        if (sexo == 0) {
            pesoIdeal = (72.7 * altura) - 58;
        } else {
            pesoIdeal = (62.1 * altura) - 44.7;
        }
        cout << fixed << setprecision(1);
        cout << "Peso ideal: " << pesoIdeal << " kg" << endl;
    }

    return 0;
}
