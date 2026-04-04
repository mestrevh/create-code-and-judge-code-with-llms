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

    double d;
    if (cin >> d) {
        double v_i = 400.0 / 3.6;
        double a = -(v_i * v_i) / (2.0 * d);

        cout << "A desaceleracao desse veiculo foi de aproximadamente: " 
             << fixed << setprecision(2) << a << " m/s^2" << endl;
    }

    return 0;
}