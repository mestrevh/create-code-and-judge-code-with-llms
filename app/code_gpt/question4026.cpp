/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    double a1, b1, a2, b2;
    char unit1, unit2;

    cin >> a1 >> b1 >> unit1;
    cin >> a2 >> b2 >> unit2;

    if (unit1 != unit2) {
        // Converte para a mesma unidade
        if (unit1 == 'm') {
            if (unit2 == 'd') a2 *= 10;
            else if (unit2 == 'c') a2 *= 100;
        } else if (unit1 == 'd') {
            if (unit2 == 'm') a1 *= 0.1;
            else if (unit2 == 'c') a2 *= 10;
        } else if (unit1 == 'c') {
            if (unit2 == 'm') a1 *= 0.01;
            else if (unit2 == 'd') a1 *= 0.1;
        }
        swap(b1, b2);
    }

    double min1 = a1 - b1;
    double max1 = a1 + b1;
    double min2 = a2 - b2;
    double max2 = a2 + b2;

    if (max1 < min2 || max2 < min1) {
        cout << "isso tem cara de desencadear um evento de distorcao espacial na proxima questao do meme man..." << endl;
    } else {
        cout << "forte." << endl;
    }

    return 0;
}
