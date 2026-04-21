/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double X, Y, Z;
    if (!(cin >> X >> Y >> Z)) return 0;

    double areaTriangle = (X * Y) / 2.0;
    double areaCircle = 3.14159 * Z * Z;
    double areaTrapezoid = ((X + Y) * Z) / 2.0;

    cout << fixed << setprecision(2);
    cout << areaTriangle << "\n";
    cout << areaCircle << "\n";
    cout << areaTrapezoid << "\n";

    return 0;
}