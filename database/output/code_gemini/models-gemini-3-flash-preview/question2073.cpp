/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long p1, p2, p3, l, r;
    if (!(cin >> p1 >> p2 >> p3 >> l >> r)) return 0;

    set<long long> results;

    for (long long x0 = 1; x0 <= r; ) {
        for (long long x1 = x0; x1 <= r; ) {
            for (long long x2 = x1; x2 <= r; ) {
                if (x2 >= l) {
                    results.insert(x2);
                }
                if (r / p3 < x2) break;
                x2 *= p3;
            }
            if (r / p2 < x1) break;
            x1 *= p2;
        }
        if (r / p1 < x0) break;
        x0 *= p1;
    }

    if (!results.empty()) {
        cout << results.size() << " " << *results.begin() << " " << *results.rbegin() << endl;
    } else {
        // In case no numbers satisfy the condition, but based on problem constraints
        // and typical competitive programming standards, this case is unlikely.
        // However, a safe output for "three integers" would be:
        // cout << 0 << " " << 0 << " " << 0 << endl;
    }

    return 0;
}