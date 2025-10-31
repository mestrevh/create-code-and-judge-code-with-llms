/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    char forma;
    double medida, area;

    cin >> forma >> medida;

    if (medida <= 0) {
        cout << "Entrada invalida!" << endl;
        return 0;
    }

    forma = tolower(forma);
    
    switch (forma) {
        case 'c':
            area = 3.141 * medida * medida;
            cout << fixed << setprecision(2) << area << endl;
            cout << "Circulo" << endl;
            break;
        case 'q':
            area = medida * medida;
            cout << fixed << setprecision(2) << area << endl;
            cout << "Quadrado" << endl;
            break;
        case 't':
            area = (sqrt(3) / 4) * medida * medida;
            cout << fixed << setprecision(2) << area << endl;
            cout << "Triangulo equilatero" << endl;
            break;
        default:
            cout << "Entrada invalida!" << endl;
            break;
    }

    return 0;
}
