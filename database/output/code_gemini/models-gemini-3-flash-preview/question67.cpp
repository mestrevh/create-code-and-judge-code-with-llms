/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double x, y;
    while (cin >> x >> y) {
        if (x == 0.0 && y == 0.0) {
            break;
        }

        double boundary = abs(x * (x * x - 4.0));
        
        if (abs(y) <= boundary + 1e-9) {
            cout << "INTERIOR\n";
        } else {
            cout << "EXTERIOR\n";
        }
    }

    return 0;
}