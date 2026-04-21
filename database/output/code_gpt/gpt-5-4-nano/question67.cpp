/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double x, y;
    while (cin >> x >> y) {
        int xi = (int)floor(x);
        int yi = (int)floor(y);

        bool interior = false;
        if (x >= 0 && y >= 0) {
            interior = true;
        } else if (x < 0 && y > 0) {
            interior = (xi == -1 && yi == 0);
        } else if (x > 0 && y < 0) {
            interior = (xi == 0 && yi == -1);
        } else if (x < 0 && y < 0) {
            interior = (xi == yi);
        }

        if (x == 0.0 && y == 0.0) interior = true;
        cout << (interior ? "INTERIOR" : "EXTERIOR") << "\n";
    }
    return 0;
}