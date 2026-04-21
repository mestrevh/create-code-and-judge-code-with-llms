/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double total_money;
    if (!(cin >> total_money)) return 0;

    int s1, s2;
    if (!(cin >> s1 >> s2)) return 0;

    double p1, p2;
    if (!(cin >> p1 >> p2)) return 0;

    double debt;
    if (!(cin >> debt)) return 0;

    double repair_cost = 0;
    if (s1 == 1 && s2 == 1) {
        repair_cost = max(p1, p2) * 0.88 + min(p1, p2);
    } else {
        if (s1 == 1) repair_cost += p1;
        if (s2 == 1) repair_cost += p2;
    }

    double total_needed = repair_cost + debt;

    if (total_money >= total_needed - 1e-9) {
        cout << "Sherliro livre do Jabbavitz e podendo voar" << endl;
    } else if (total_money >= repair_cost - 1e-9) {
        cout << "Sherliro consertou mas ta lascado com o Jabbavitz" << endl;
        cout << "faltam " << fixed << setprecision(2) << (total_needed - total_money) << " Napoleocoins" << endl;
    } else {
        cout << "Sherliro vai ser perseguido hoje e ainda ta sem nave" << endl;
        cout << "faltam " << fixed << setprecision(2) << (total_needed - total_money) << " Napoleocoins" << endl;
    }

    return 0;
}