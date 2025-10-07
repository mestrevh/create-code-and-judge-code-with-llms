/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double distancia;
    char tipo;
    cin >> distancia >> tipo;

    double consumo;

    switch (tipo) {
        case 'A':
        case 'a':
            consumo = distancia / 12;
            cout << fixed << setprecision(2) << consumo << endl;
            break;
        case 'B':
        case 'b':
            consumo = distancia / 9;
            cout << fixed << setprecision(2) << consumo << endl;
            break;
        case 'C':
        case 'c':
            consumo = distancia / 8;
            cout << fixed << setprecision(2) << consumo << endl;
            break;
        default:
            cout << "Tipo inválido!" << endl;
            break;
    }
    return 0;
}
