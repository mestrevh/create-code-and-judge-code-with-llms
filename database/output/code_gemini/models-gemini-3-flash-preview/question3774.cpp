/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int raizes(float A, float B, float C, float *x1, float *x2) {
    float delta = (B * B) - (4.0f * A * C);
    if (delta < 0) {
        return 0;
    } else if (delta == 0) {
        *x1 = -B / (2.0f * A);
        return 1;
    } else {
        float sqrt_delta = sqrt(delta);
        *x1 = (-B + sqrt_delta) / (2.0f * A);
        *x2 = (-B - sqrt_delta) / (2.0f * A);
        return 2;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    float A, B, C;
    if (!(cin >> A >> B >> C)) return 0;

    float r1, r2;
    int num_solucoes = raizes(A, B, C, &r1, &r2);

    cout << fixed << setprecision(2);
    if (num_solucoes == 2) {
        cout << r1 << " " << r2 << "\n";
        cout << 2 << endl;
    } else if (num_solucoes == 1) {
        cout << r1 << "\n";
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}