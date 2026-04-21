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

    double n1, n2;
    if (cin >> n1 >> n2) {
        cout << fixed << setprecision(2);
        cout << n1 << " + " << n2 << " = " << (n1 + n2) << "\n";
        cout << n1 << " - " << n2 << " = " << (n1 - n2) << "\n";
        cout << n1 << " * " << n2 << " = " << (n1 * n2) << "\n";
        if (n2 != 0) {
            cout << n1 << " / " << n2 << " = " << (n1 / n2) << "\n";
        } else {
            // Standard handling for division by zero in CP, 
            // though not explicitly mentioned in the problem.
            cout << n1 << " / " << n2 << " = inf" << "\n";
        }
    }

    return 0;
}