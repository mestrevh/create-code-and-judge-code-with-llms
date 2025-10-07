/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {
    int impulso, distancia, peso;
    double altura;
    string yoshi;

    cin >> impulso >> altura >> distancia >> peso >> yoshi;

    if (yoshi == "Sim") {
        peso += 50;
        impulso += 5;
    }

    double altura_maxima = pow(impulso, 3) / (sqrt(altura) + distancia / 2.0 + peso / 3.0);

    if (altura_maxima >= 100) {
        cout << "Voce consegue" << endl;
    } else {
        cout << "Isso e perda de tempo" << endl;
    }

    return 0;
}
