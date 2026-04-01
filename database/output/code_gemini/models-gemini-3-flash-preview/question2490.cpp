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

    double xa, ya, xb, yb, xc, yc;
    if (!(cin >> xa >> ya >> xb >> yb >> xc >> yc)) return 0;

    double distAB = sqrt((xb - xa) * (xb - xa) + (yb - ya) * (yb - ya));
    double distBC = sqrt((xc - xb) * (xc - xb) + (yc - yb) * (yc - yb));
    double distCA = sqrt((xa - xc) * (xa - xc) + (ya - yc) * (ya - yc));

    cout << fixed << setprecision(2);
    cout << "A-B: " << distAB << "\n";
    cout << "B-C: " << distBC << "\n";
    cout << "C-A: " << distCA << "\n";

    return 0;
}