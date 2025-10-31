/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double calcula_tempo(int x0, int z0, int xf, int zf, double velocidade) {
    double distancia = sqrt(pow(xf - x0, 2) + pow(zf - z0, 2));
    return distancia / velocidade;
}

int main() {
    int x0, z0, xf, zf;
    double velocidade;

    cin >> x0 >> z0 >> xf >> zf >> velocidade;

    double tempo = calcula_tempo(x0, z0, xf, zf, velocidade);

    cout << fixed << setprecision(2);
    cout << "Milos esta no ponto (" << x0 << ", " << z0 << ") indo para ("
         << xf << ", " << zf << ") e provavelmente ira chegar em " << tempo << " horas." << endl;

    return 0;
}
