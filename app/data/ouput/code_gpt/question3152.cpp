/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
using namespace std;

bool distanciaValida(double x1, double y1, double x2, double y2) {
    return hypot(x2 - x1, y2 - y1) >= 2.0;
}

int main() {
    double ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;

    if (distanciaValida(ax, ay, bx, by) && distanciaValida(ax, ay, cx, cy) && distanciaValida(bx, by, cx, cy)) {
        cout << "POSICAO VALIDA" << endl;
    } else {
        cout << "POSICAO INVALIDA" << endl;
    }
    return 0;
}
