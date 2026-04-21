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

    double initial_balance, total_debits, total_credits;
    while (cin >> initial_balance >> total_debits >> total_credits) {
        cout << "Informe o saldo inicial do cliente:\n";
        cout << "Informe o total de debitos adquiridos pelo cliente:\n";
        cout << "Informe o total de creditos adquiridos pelo cliente:\n";

        double final_balance = initial_balance - total_debits + total_credits;

        if (final_balance > 1e-9) {
            cout << "Saldo positivo em R$ " << setprecision(17) << final_balance << "\n";
        } else if (final_balance < -1e-9) {
            cout << "Saldo negativo em R$ " << setprecision(17) << final_balance << "\n";
        } else {
            cout << "Saldo Zero\n";
        }
    }

    return 0;
}