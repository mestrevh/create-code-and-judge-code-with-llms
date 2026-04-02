/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long v;
    int d;
    if (!(cin >> v >> d)) return 0;

    long long total_cost = 0;
    long long total_bowls = 0;

    for (int i = 0; i < d; ++i) {
        long long t;
        if (!(cin >> t)) break;
        total_bowls += t;
        if (t == 1) {
            total_cost += 10;
        } else if (t >= 2 && t <= 10) {
            total_cost += t * 9;
        } else if (t > 10) {
            total_cost += t * 8;
        }
    }

    if (total_bowls == 0) {
        cout << "Naruto nao apareceu para comer" << endl;
    } else if (v >= total_cost) {
        cout << "Naruto conseguiu pagar a sua conta!" << endl;
    } else {
        cout << "Naruto, faltam " << (total_cost - v) << " ryos!" << endl;
    }

    return 0;
}