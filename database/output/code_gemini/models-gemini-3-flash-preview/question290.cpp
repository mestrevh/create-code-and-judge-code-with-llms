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

    int id1, q1;
    double p1;
    int id2, q2;
    double p2;

    if (cin >> id1 >> q1 >> p1 >> id2 >> q2 >> p2) {
        double total = (q1 * p1) + (q2 * p2);
        cout << "VALOR A PAGAR: R$ " << fixed << setprecision(2) << total << "\n";
    }

    return 0;
}