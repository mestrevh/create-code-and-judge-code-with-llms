/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double ri, re;
    if (cin >> ri >> re) {
        const double PI = acos(-1.0);
        double area = PI * (re * re - ri * ri);
        cout << fixed << setprecision(2) << area << endl;
    }

    return 0;
}