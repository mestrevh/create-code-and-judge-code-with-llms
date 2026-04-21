/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * Competitive Programming Solution
 * Persona: Grandmaster
 * Complexity: O(N * log_b(X))
 */

void solve() {
    int n;
    if (!(cin >> n)) return;

    const char mapping[] = "0123456789ABCDEF";

    while (n--) {
        long long x;
        int b;
        if (!(cin >> x >> b)) break;

        if (x == 0) {
            cout << "0\n";
            continue;
        }

        bool negative = false;
        if (x < 0) {
            negative = true;
            x = -x;
        }

        string result = "";
        while (x > 0) {
            result.push_back(mapping[x % b]);
            x /= b;
        }

        if (negative) {
            result.push_back('-');
        }

        reverse(result.begin(), result.end());
        cout << result << "\n";
    }
}

int main() {
    // Fast I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}