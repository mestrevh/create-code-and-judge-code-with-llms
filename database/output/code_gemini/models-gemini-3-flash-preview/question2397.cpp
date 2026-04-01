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

    int n;
    if (!(cin >> n)) return 0;

    double total = 0.0;
    for (int i = 0; i < n; ++i) {
        int code;
        int quantity;
        cin >> code >> quantity;

        double price = 0.0;
        switch (code) {
            case 1001: price = 1.50; break;
            case 1002: price = 2.50; break;
            case 1003: price = 3.50; break;
            case 1004: price = 4.50; break;
            case 1005: price = 5.50; break;
            default: break;
        }
        total += price * quantity;
    }

    cout << fixed << setprecision(2) << total << "\n";

    return 0;
}