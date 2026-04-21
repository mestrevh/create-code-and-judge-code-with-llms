/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

double VolumeEsfera(double raio) {
    const double PI = 3.1416;
    return (4.0 * PI * raio * raio * raio) / 3.0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double r;
    cout << fixed << setprecision(2);
    
    for (int i = 0; i < 3; ++i) {
        if (cin >> r) {
            cout << VolumeEsfera(r) << "\n";
        }
    }

    return 0;
}