/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    double a = y2 - y1;
    double b = -(x2 - x1);
    double c = x2 * y1 - x1 * y2;

    cout << fixed << setprecision(2) << "(" << a << "x) + (" << b << "y) + (" << c << ") = 0" << endl;
    return 0;
}
