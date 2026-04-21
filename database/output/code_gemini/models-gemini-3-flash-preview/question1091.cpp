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
    if (!(cin >> n)) {
        return 0;
    }

    if (n <= 0) {
        cout << fixed << setprecision(2) << 0.00 << endl;
        return 0;
    }

    double totalSum = 0.0;
    for (int i = 1; i <= n; ++i) {
        if (i % 2 != 0) {
            totalSum += (double)i / (2.0 * (i + 1));
        } else {
            totalSum += 1.0;
        }
    }

    cout << fixed << setprecision(2) << totalSum << "\n";

    for (int i = 1; i <= n; ++i) {
        if (i % 2 != 0) {
            cout << i << "/" << (2 * (i + 1));
        } else {
            cout << "1";
        }
        if (i < n) {
            cout << " + ";
        }
    }
    cout << endl;

    return 0;
}