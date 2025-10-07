/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    char sexo;
    double altura;
    cin >> sexo >> altura;

    if (altura <= 0) {
        cout << "Altura invalida." << endl;
    } else if (sexo == 'm') {
        double pesoIdeal = (72.7 * altura) - 58;
        cout << fixed << setprecision(2) << pesoIdeal << endl;
    } else if (sexo == 'f') {
        double pesoIdeal = (62.1 * altura) - 44.7;
        cout << fixed << setprecision(2) << pesoIdeal << endl;
    } else {
        cout << "O sexo informado eh invalido." << endl;
    }
    
    return 0;
}
