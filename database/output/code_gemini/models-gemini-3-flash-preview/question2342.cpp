/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

void reduzir(double *x, double *y) {
    if (x != nullptr && y != nullptr) {
        *x = *x - *y;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double a, b;
    if (cin >> a >> b) {
        reduzir(&a, &b);
        cout << fixed << setprecision(2) << a << " " << b << "\n";
    }

    return 0;
}