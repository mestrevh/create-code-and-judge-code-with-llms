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

    double distance;
    char type;

    if (!(cin >> distance >> type)) {
        return 0;
    }

    double consumption = 0.0;
    bool valid = true;

    if (type == 'A') {
        consumption = distance / 12.0;
    } else if (type == 'B') {
        consumption = distance / 9.0;
    } else if (type == 'C') {
        consumption = distance / 8.0;
    } else {
        valid = false;
    }

    if (valid) {
        cout << fixed << setprecision(2) << consumption << endl;
    } else {
        cout << "Tipo inválido!" << endl;
    }

    return 0;
}