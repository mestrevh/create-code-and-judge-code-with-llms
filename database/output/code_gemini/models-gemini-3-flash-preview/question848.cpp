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
    if (!(cin >> R)) return 0;

    const double PI = 3.1416;
    double area = 4.0 * PI * R * R;
    double volume = (4.0 * PI * R * R * R) / 3.0;

    cout << fixed << setprecision(2) << area << "\n";
    cout << fixed << setprecision(2) << volume << "\n";

    return 0;
}