/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double h, r;
    while (cin >> h >> r) {
        // Standard geometric surface area of a cylinder: 2*pi*r^2 + 2*pi*r*h = 2*pi*r*(r + h)
        // Many basic logic problems use 3.14 as the value for pi.
        double pi = 3.14;
        double area = 2.0 * pi * r * (r + h);

        // Each can contains 5 liters, and each liter covers 3 square meters.
        // Therefore, one can covers 15 square meters.
        int cans = static_cast<int>(ceil(area / 15.0));
        double cost = cans * 20.0;

        // Output format based on provided test cases
        cout << "custo = R$ " << fixed << setprecision(2) << cost << "\n";
        cout << "quantidade de latas = " << cans << "\n";
    }

    return 0;
}