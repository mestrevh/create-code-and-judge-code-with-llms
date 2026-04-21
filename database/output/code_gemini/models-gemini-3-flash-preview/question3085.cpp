/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        long long a, b;
        if (!(cin >> a >> b)) break;

        long long cnt = 0;
        // The condition (i * j) + (i + j) = conc(i, j) simplifies to:
        // i * j + i + j = i * 10^d + j, where d is the number of digits of j.
        // i * j + i = i * 10^d
        // i * (j + 1) = i * 10^d
        // Since i >= 1, we can divide by i:
        // j + 1 = 10^d
        // This means j must be of the form 10^d - 1 (e.g., 9, 99, 999, ...).
        // For each such valid j, any i from 1 to A works.
        
        for (long long val = 9; val <= b; ) {
            cnt++;
            // Check if adding another digit would exceed the maximum value of B
            // or overflow the long long before the loop condition check.
            if (val > 1000000000LL) break;
            val = val * 10 + 9;
        }

        cout << a * cnt << "\n";
    }

    return 0;
}