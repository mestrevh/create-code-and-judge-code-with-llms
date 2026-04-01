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

    double radius, degrees;
    while (cin >> radius >> degrees) {
        const double PI = 3.14;
        
        double arcLength = (degrees * 2.0 * PI * radius) / 360.0;
        double sectorArea = (degrees * PI * radius * radius) / 360.0;

        cout << fixed << setprecision(2) << arcLength << "\n";
        cout << fixed << setprecision(2) << sectorArea << "\n";
    }

    return 0;
}