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

    double A, B, C, D, E;
    
    if (cin >> A >> B >> C >> D >> E) {
        double divisor = D + E;
        if (divisor != 0) {
            double result = (A + B + C) / divisor;
            cout << fixed << setprecision(2) << result << endl;
        } else {
            // Usually in competitive programming, division by zero isn't expected unless specified.
            // Given the test cases, we assume D+E != 0.
        }
    }

    return 0;
}