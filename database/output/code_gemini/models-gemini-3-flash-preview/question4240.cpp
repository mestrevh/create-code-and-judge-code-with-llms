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

    double a, b;
    if (cin >> a >> b) {
        double third_angle = 180.0 - (a + b);

        cout << "Informe o angulo 1 " << "\n";
        cout << "Informe o angulo 2 " << "\n";
        cout << "O terceiro angulo = " << fixed << setprecision(3) << third_angle << "\n";
    }

    return 0;
}