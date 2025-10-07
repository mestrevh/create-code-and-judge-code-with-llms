/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int V, D, T, total_cost = 0;

    cin >> V >> D;

    for (int i = 0; i < D; i++) {
        cin >> T;
        if (T == 1) {
            total_cost += 10;
        } else if (T >= 2 && T <= 10) {
            total_cost += T * 10 * 0.9;
        } else if (T > 10) {
            total_cost += T * 10 * 0.8;
        }
    }

    if (total_cost == 0) {
        cout << "Naruto nao apareceu para comer" << endl;
    } else if (V >= total_cost) {
        cout << "Naruto conseguiu pagar a sua conta!" << endl;
    } else {
        cout << "Naruto, faltam " << total_cost - V << " ryos!" << endl;
    }

    return 0;
}
