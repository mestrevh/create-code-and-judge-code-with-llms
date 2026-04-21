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

    double polegadas;
    if (cin >> polegadas) {
        double mm = polegadas * 25.4;
        cout << fixed << setprecision(1) << polegadas << " polegada(s) eh o mesmo que " << mm << " mm" << endl;
    }

    return 0;
}