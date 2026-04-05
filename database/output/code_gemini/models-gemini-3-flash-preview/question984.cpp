/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    long long mn, mx;
    bool started = false;

    while (cin >> n && n != -1) {
        if (!started) {
            mn = mx = n;
            started = true;
        } else {
            if (n < mn) mn = n;
            if (n > mx) mx = n;
        }
        cout << "menor=" << mn << "||MAIOR=" << mx << "\n";
    }

    if (started) {
        if (mn == 0) {
            cout << 0 << "\n";
        } else {
            for (long long i = mn; i <= mx; ) {
                if (i > mn) cout << "||";
                cout << i;
                if (mx - i < mn) break;
                i += mn;
            }
            cout << "\n";
        }
    }

    return 0;
}