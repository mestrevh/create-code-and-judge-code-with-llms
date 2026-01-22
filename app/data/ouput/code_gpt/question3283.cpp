/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int X, Y, Z;
    cin >> X >> Y >> Z;

    double areaTriangle = (X * Y) / 2.0;
    double areaCircle = 3.14159 * pow(Z, 2);
    double areaTrapezoid = (X + Y) * Y / 2.0;

    cout << fixed << setprecision(2);
    cout << areaTriangle << endl;
    cout << areaCircle << endl;
    cout << areaTrapezoid << endl;

    return 0;
}
