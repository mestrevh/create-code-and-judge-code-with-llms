/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n) || n <= 0) {
        cout << "Nenhuma nota informada!" << "\n";
        return 0;
    }

    vector<double> notes(n);
    double total_sum = 0.0;
    for (int i = 0; i < n; ++i) {
        if (cin >> notes[i]) {
            total_sum += notes[i];
        }
    }

    cout << "[";
    for (int i = 0; i < n; ++i) {
        cout << fixed << setprecision(1) << notes[i];
        if (i < n - 1) {
            cout << ", ";
        }
    }
    cout << "]" << "\n";
    cout << fixed << setprecision(2) << total_sum << "\n";

    return 0;
}