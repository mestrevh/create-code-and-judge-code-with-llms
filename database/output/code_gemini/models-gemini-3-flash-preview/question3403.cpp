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

    double x1, y1, z1;
    double x2, y2, z2;

    if (!(cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2)) return 0;

    double dx = x2 - x1;
    double dy = y2 - y1;
    double dz = z2 - z1;

    double distance = sqrt(dx * dx + dy * dy + dz * dz);

    cout << fixed << setprecision(2) << distance << endl;

    return 0;
}