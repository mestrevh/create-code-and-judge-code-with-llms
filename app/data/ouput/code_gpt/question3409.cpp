/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    double x, y, x1, y1, x2, y2;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;

    if ((x >= x1 && x <= x2) && (y >= y1 && y <= y2)) {
        cout << "Dentro" << endl;
    } else {
        cout << "Fora" << endl;
    }

    return 0;
}
