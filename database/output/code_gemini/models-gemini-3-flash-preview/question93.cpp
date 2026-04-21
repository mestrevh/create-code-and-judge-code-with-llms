/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll H, W;
    while (cin >> H >> W && (H != 0 || W != 0)) {
        if (H == 1 && W == 1) {
            cout << "0 1\n";
            continue;
        }

        ll n = -1, k = -1;
        for (int tk = 1; tk <= 60; ++tk) {
            ll tn;
            if (W == 1) {
                tn = 1;
            } else {
                double tn_d = pow((double)W, 1.0 / tk);
                tn = (ll)round(tn_d);
            }

            for (ll ctn = max(1LL, tn - 1); ctn <= tn + 1; ++ctn) {
                ll valW = 1;
                bool failW = false;
                for (int i = 0; i < tk; ++i) {
                    if (__builtin_mul_overflow(valW, ctn, &valW)) {
                        failW = true;
                        break;
                    }
                }
                if (failW || valW != W) continue;

                ll valH = 1;
                bool failH = false;
                for (int i = 0; i < tk; ++i) {
                    if (__builtin_mul_overflow(valH, ctn + 1, &valH)) {
                        failH = true;
                        break;
                    }
                }
                if (failH || valH != H) continue;

                n = ctn;
                k = tk;
                break;
            }
            if (n != -1) break;
        }

        ll nw_cats;
        if (n == 1) {
            nw_cats = k;
        } else {
            nw_cats = (W - 1) / (n - 1);
        }

        unsigned __int128 h128 = H;
        unsigned __int128 w128 = W;
        unsigned __int128 n128 = n;
        unsigned __int128 total_h = h128 * (n128 + 1) - n128 * w128;

        cout << nw_cats << " " << (ll)total_h << "\n";
    }

    return 0;
}