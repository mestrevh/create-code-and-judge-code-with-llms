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

    long long total_nails_needed = 0;
    int n;

    while (cin >> n) {
        if (n % 2 != 0) {
            break;
        }
        total_nails_needed += n;
    }

    if (total_nails_needed == 0) {
        cout << fixed << setprecision(2) << 0.00 << "\n";
        cout << 0 << "\n";
        return 0;
    }

    long long boxes = (total_nails_needed + 11) / 12;
    double total_cost = boxes * 7.89;
    long long remaining = (boxes * 12) - total_nails_needed;

    cout << fixed << setprecision(2) << total_cost << "\n";
    cout << remaining << "\n";

    return 0;
}