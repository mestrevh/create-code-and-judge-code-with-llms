/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;
    if (n <= 0) return 0;

    double mn = 0, mx = 0, sum = 0;
    int pairs_count = 0;

    for (int i = 0; i < n; ++i) {
        double current;
        cin >> current;
        if (i == 0) {
            mn = current;
            mx = current;
        } else {
            if (current < mn) mn = current;
            if (current > mx) mx = current;
        }
        sum += current;
        
        // Em problemas de maratona, a paridade de números reais geralmente 
        // refere-se ao valor inteiro.
        if ((int)current % 2 == 0) {
            pairs_count++;
        }
    }

    cout << fixed << setprecision(1) << mn << "\n";
    cout << fixed << setprecision(1) << mx << "\n";
    cout << fixed << setprecision(2) << (static_cast<double>(pairs_count) * 100.0 / n) << "\n";
    cout << fixed << setprecision(2) << (sum / n) << "\n";

    return 0;
}