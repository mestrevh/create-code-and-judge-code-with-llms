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

    double n1, n2, n3, n4;
    while (cin >> n1 >> n2 >> n3 >> n4) {
        double media = (n1 * 2.0 + n2 * 2.0 + n3 * 3.0 + n4 * 3.0) / 10.0;
        cout << "A média ponderada será: " << fixed << setprecision(2) << media << "\n";
    }

    return 0;
}