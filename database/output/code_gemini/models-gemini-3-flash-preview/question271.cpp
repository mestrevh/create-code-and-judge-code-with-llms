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

    double R;
    while (cin >> R) {
        const double PI = 3.14159;
        // Area in cm^2 = PI * R^2
        // Area in m^2 = (PI * R^2) / 100^2
        double area_m2 = (PI * R * R) / 10000.0;
        
        cout << "Area = " << fixed << setprecision(4) << area_m2 << "\n";
    }

    return 0;
}