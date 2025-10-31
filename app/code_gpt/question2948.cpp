/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

int main() {
    char mapa[5][10];
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 10; ++j)
            cin >> mapa[i][j];

    double menorTempo = numeric_limits<double>::max();
    int melhorX = -1, melhorY = -1;

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (mapa[i][j] == '0' || mapa[i][j] == '1') {
                double distancia = sqrt(i * i + j * j);
                double tempo = distancia * 20 + (mapa[i][j] == '0' ? 40 : 0);
                
                if (tempo < menorTempo || (tempo == menorTempo && melhorY > i)) {
                    menorTempo = tempo;
                    melhorX = j;
                    melhorY = i;
                }
            }
        }
    }

    if (melhorX == -1) {
        cout << "Tristemente voce vai ter que aturar os PCs do grad 4" << endl;
    } else {
        cout << "Vai la pro computador " << melhorX << " da fileira " << melhorY << endl;
    }

    return 0;
}
