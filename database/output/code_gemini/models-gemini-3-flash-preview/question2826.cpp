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

    long long g;
    if (cin >> g) {
        double liters = (double)g * 3.7854;
        cout << g << " GALÕES -> " << fixed << setprecision(2) << liters << " LITROS" << endl;
    }

    return 0;
}