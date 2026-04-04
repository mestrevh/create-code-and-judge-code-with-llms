/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

typedef __int128_t int128;

int get_sum(int128 n) {
    int s = 0;
    while (n > 0) {
        s += (int)(n % 10);
        n /= 10;
    }
    return s;
}

void solve() {
    unsigned long long n_in;
    int s_in;
    if (!(cin >> n_in >> s_in)) return;

    int128 n = n_in;
    int128 s = s_in;

    if (get_sum(n) <= s) {
        cout << "0\n";
        return;
    }

    int128 min_x = -1;
    int128 p10 = 1;

    for (int k = 0; k <= 19; ++k) {
        int128 x = (n / p10 + 1) * p10;
        if (get_sum(x) <= s) {
            if (min_x == -1 || x < min_x) {
                min_x = x;
            }
        }
        if (k < 19) {
            p10 *= 10;
        } else {
            break;
        }
    }

    unsigned long long diff = (unsigned long long)(min_x - n);
    cout << diff << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }

    return 0;
}