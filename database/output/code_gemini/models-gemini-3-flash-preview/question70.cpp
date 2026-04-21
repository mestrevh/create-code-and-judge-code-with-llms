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

    long long x, n;
    while (cin >> x >> n && (x != 0 || n != 0)) {
        double series_sum = 0.0;
        double current_term = 1.0;

        for (int i = 0; i < n; ++i) {
            series_sum += current_term;
            // The formula derived from test cases is x/2 + sum(i=0 to n-1) [(-1)^i * x^(2i) / (2i+1)!]
            // Term i=0: x^0 / 1! = 1
            // Term i=1: -x^2 / 3!
            // Term i=2: x^4 / 5!
            // Each subsequent term multiplies by -x^2 / ((2i+2)*(2i+3))
            current_term *= -(double)x * x / ((2.0 * i + 2.0) * (2.0 * i + 3.0));
        }

        double result = (double)x / 2.0 + series_sum;
        cout << fixed << setprecision(6) << result << "\n";
    }

    return 0;
}