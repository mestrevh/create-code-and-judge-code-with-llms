/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double balanceClara = 0.0;
    double balanceDiana = 0.0;

    for (int i = 0; i < 6; i++) {
        double value;
        string name;
        if (!(cin >> value)) return 0;
        cin >> name;

        if (!name.empty() && (name[0] == 'C' || name[0] == 'c')) {
            balanceClara += value;
        } else {
            balanceDiana += value;
        }
    }

    double perPerson = (balanceClara + balanceDiana) / 2.0;
    double claraDue = balanceClara - perPerson;

    if (fabs(claraDue) < 1e-9) {
        cout << "MORADORAS QUITES\n";
        return 0;
    }

    cout.setf(std::ios::fixed);
    cout << setprecision(2);

    if (claraDue > 0) {
        cout << "DIANA\n" << claraDue << "\n";
    } else {
        cout << "CLARA\n" << (-claraDue) << "\n";
    }

    return 0;
}