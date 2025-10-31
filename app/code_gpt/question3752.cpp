/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
using namespace std;

void equacaoredx(int c, float e) {
    float a = c / (2.0 * e);
    float b = sqrt(a * a * (1 - e * e));
    cout << "FOCOS EM X\n";
    cout << "x^2/" << a * a << " + y^2/" << b * b << " = 1\n";
}

void equacaoredy(int c, float e) {
    float b = c / (2.0 * e);
    float a = sqrt(b * b * (1 - e * e));
    cout << "FOCOS EM Y\n";
    cout << "x^2/" << b * b << " + y^2/" << a * a << " = 1\n";
}

int main() {
    int x1, y1, x2, y2;
    float e;
    cin >> x1 >> y1 >> x2 >> y2 >> e;

    if (x1 == x2) {
        equacaoredy(abs(y1 - y2), e);
    } else {
        equacaoredx(abs(x1 - x2), e);
    }
    return 0;
}
