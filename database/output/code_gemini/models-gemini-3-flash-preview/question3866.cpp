/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll custom_pow(ll base, int exp) {
    ll res = 1;
    for (int i = 0; i < exp; ++i) {
        res *= base;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    for (int i = 0; i < n; ++i) {
        vector<ll> row(m);
        for (int j = 0; j < m; ++j) {
            cin >> row[j];
        }

        for (ll r = 0; r <= 11; ++r) {
            bool valid = true;
            for (int j = 0; j < m; ++j) {
                if (row[j] != -1) {
                    if (custom_pow(r, j) != row[j]) {
                        valid = false;
                        break;
                    }
                }
            }
            if (valid) {
                for (int j = 0; j < m; ++j) {
                    cout << custom_pow(r, j) << (j == m - 1 ? "" : " ");
                }
                cout << "\n";
                break;
            }
        }
    }

    return 0;
}