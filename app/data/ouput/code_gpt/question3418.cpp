/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

void extendedEuclidean(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return;
    }
    int x1, y1;
    extendedEuclidean(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
}

int main() {
    int a, b, x, y;
    cin >> a >> b;

    extendedEuclidean(a, b, x, y);
    cout << x << "*" << b << " + " << -y << "*" << a << endl;

    return 0;
}
