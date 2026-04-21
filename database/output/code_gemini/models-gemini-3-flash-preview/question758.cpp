/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    int F;
    while (cin >> F) {
        int total_internal_dr = 0;
        int n_rd = 0, n_r = 0, n_d = 0;

        for (int i = 0; i < F; ++i) {
            string S;
            cin >> S;
            string L = "";
            for (char c : S) {
                if (c == 'D' || c == 'R') {
                    if (L.empty() || L.back() != c) {
                        L += c;
                    }
                }
            }

            int dr = 0;
            string rem = "";
            if (!L.empty()) {
                if (L[0] == 'D') {
                    dr = L.length() / 2;
                    if (L.length() % 2 != 0) {
                        rem = "D";
                    }
                } else {
                    dr = (L.length() - 1) / 2;
                    if (L.length() % 2 == 0) {
                        rem = "RD";
                    } else {
                        rem = "R";
                    }
                }
            }

            total_internal_dr += dr;
            if (rem == "RD") n_rd++;
            else if (rem == "R") n_r++;
            else if (rem == "D") n_d++;
        }

        int extra = 0;
        if (n_rd > 0) {
            extra = n_rd - 1;
            if (n_r > 0) {
                extra++;
                n_r--;
            }
            if (n_d > 0) {
                extra++;
                n_d--;
            }
        }
        extra += min(n_r, n_d);

        cout << total_internal_dr + extra << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}