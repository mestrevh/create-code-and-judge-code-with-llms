/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long debt, max_payment;
    if (!(cin >> debt >> max_payment)) return 0;

    while (debt > 0) {
        cout << "(antes) " << debt << "\n";
        long long current_payment = min(debt, max_payment);
        debt -= current_payment;
        cout << "(depois) " << debt << "\n";
    }

    return 0;
}