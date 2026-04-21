/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n0_ll, n_ll;
    if (!(cin >> n0_ll >> n_ll)) return 0;

    __int128 n0 = n0_ll;
    __int128 n = n_ll;

    if (n < n0) {
        cout << 0 << endl;
    } else {
        __int128 count = n - n0 + 1;
        __int128 sum = (n0 + n) * count / 2;

        if (sum == 0) {
            cout << 0 << endl;
        } else {
            string s = "";
            while (sum > 0) {
                s += (char)('0' + (long long)(sum % 10));
                sum /= 10;
            }
            reverse(s.begin(), s.end());
            cout << s << endl;
        }
    }

    return 0;
}