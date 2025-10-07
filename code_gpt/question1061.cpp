/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    float r1, r2;
    cin >> r1 >> r2;
    float area1 = 3.14 * r1 * r1;
    float area2 = 3.14 * r2 * r2;

    if (area1 > area2) {
        cout << "Primeiro circulo" << endl;
    } else if (area1 < area2) {
        cout << "Segundo circulo" << endl;
    } else {
        cout << "Iguais" << endl;
    }
    return 0;
}
