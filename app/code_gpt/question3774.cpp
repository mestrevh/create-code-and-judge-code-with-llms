/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int raizes(float A, float B, float C, float* x1, float* x2) {
    float delta = B * B - 4 * A * C;
    if (delta > 0) {
        *x1 = (-B + sqrt(delta)) / (2 * A);
        *x2 = (-B - sqrt(delta)) / (2 * A);
        return 2;
    } else if (delta == 0) {
        *x1 = -B / (2 * A);
        return 1;
    }
    return 0;
}

int main() {
    float A, B, C, x1, x2;
    cin >> A >> B >> C;
    
    int numRaizes = raizes(A, B, C, &x1, &x2);
    
    if (numRaizes == 2) {
        cout << fixed << setprecision(2) << x1 << " " << x2 << endl;
    } else if (numRaizes == 1) {
        cout << fixed << setprecision(2) << x1 << endl;
    }
    cout << numRaizes << endl;

    return 0;
}
