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

    double x, y;
    while (cin >> x >> y) {
        double media = (x + y) / 2.0;
        cout << fixed << setprecision(2) << media << "\n";
    }

    return 0;
}