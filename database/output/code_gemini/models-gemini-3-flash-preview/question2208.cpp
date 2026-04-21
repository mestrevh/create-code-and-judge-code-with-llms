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

    if (n <= 0) return 0;

    long double sum = 0.0;
    long double current_term = 1.0;

    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            current_term /= (long double)i;
        }
        sum += current_term;
        
        // Precision optimization: if the term is smaller than the precision 
        // of a long double, further terms won't affect the sum.
        if (i > 50 && current_term < 1e-25) {
            break;
        }
    }

    cout << fixed << setprecision(15) << (double)sum << endl;

    return 0;
}

// Complexity: O(min(n, K)) where K is the number of terms until precision limit (~30-50).
// Space: O(1).