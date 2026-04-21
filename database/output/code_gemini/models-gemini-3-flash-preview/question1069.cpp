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

    char op;
    if (!(cin >> op)) return 0;

    cout << fixed << setprecision(2);

    if (op == 'Q') {
        double side;
        cin >> side;
        cout << (side * side) << "\n";
        cout << (4.0 * side) << "\n";
    } else if (op == 'R') {
        double h, w;
        cin >> h >> w;
        cout << (h * w) << "\n";
        cout << (2.0 * (h + w)) << "\n";
    } else if (op == 'C') {
        double r;
        const double pi = 3.14;
        cin >> r;
        cout << (pi * r * r) << "\n";
        cout << (2.0 * pi * r) << "\n";
    } else {
        cout << "Nenhuma figura selecionada" << endl;
    }

    return 0;
}