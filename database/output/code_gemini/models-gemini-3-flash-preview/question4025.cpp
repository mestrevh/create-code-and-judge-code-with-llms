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

    int s1, s2, q1, q2, r;
    if (!(cin >> s1 >> s2 >> q1 >> q2 >> r)) return 0;

    auto get_cost = [](int id, int ml) -> double {
        double base = 0.0;
        double discount = 0.0;

        if (id == 1) {
            base = 2.0;
            if (ml <= 500) discount = 0.05;
            else discount = 0.10;
        } else if (id == 2) {
            base = 3.0;
            if (ml <= 500) discount = 0.03;
            else discount = 0.06;
        } else if (id == 3) {
            base = 4.0;
            if (ml <= 500) discount = 0.04;
            else discount = 0.08;
        }

        return (ml / 100.0) * base * (1.0 - discount);
    };

    double total_cost = get_cost(s1, q1) + get_cost(s2, q2);

    if ((double)r < total_cost - 1e-9) {
        cout << "Carambolas! O shake JA ERA." << endl;
    } else {
        int multiplier = (int)((double)r / total_cost + 1e-9);
        if (multiplier >= 2) {
            cout << "Yeah! Shake " << multiplier << " vezes mais." << endl;
        } else {
            cout << "De qualquer forma matamos nossa sede de shake." << endl;
        }
    }

    return 0;
}