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

    double total_prize;
    if (cin >> total_prize) {
        cout << fixed << setprecision(2);
        cout << total_prize * 0.60 << "\n";
        cout << total_prize * 0.30 << "\n";
        cout << total_prize * 0.10 << "\n";
    }

    return 0;
}