/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    vector<long long> a(T);
    for (int i = 0; i < T; i++) cin >> a[i];
    long long X;
    cin >> X;

    bool allNonNeg = true, allNonPos = true;
    for (auto v : a) {
        if (v < 0) allNonNeg = false;
        if (v > 0) allNonPos = false;
    }

    long long sum = 0;
    for (auto v : a) sum += v;

    if (X == 0) {
        cout << 0 << " " << 0 << "\n";
        return 0;
    }

    if (allNonNeg) {
        if (sum == 0) {
            cout << "Esse numero deve estar errado...\n";
            return 0;
        }
        long long S0 = X / sum;
        long long rem = X - S0 * sum;

        long long cur = 0;
        int pos = -1;
        for (int i = 0; i < T; i++) {
            cur += a[i];
            if (cur == rem) {
                pos = i;
                break;
            }
        }

        if (pos == -1) {
            long long cur2 = 0;
            for (int i = 0; i < T; i++) {
                cur2 += a[i];
                if (cur2 == rem + sum) {
                    pos = i;
                    S0 += 1;
                    break;
                }
                if (cur2 > rem + sum) break;
            }
        }

        if (pos == -1) {
            cout << "Esse numero deve estar errado...\n";
            return 0;
        }
        cout << pos << " " << S0 << "\n";
    } else if (allNonPos) {
        if (sum == 0) {
            cout << "Esse numero deve estar errado...\n";
            return 0;
        }
        long long q = X / sum;
        long long r = X - q * sum;

        long long rem = r;
        long long cur = 0;
        int pos = -1;
        for (int i = 0; i < T; i++) {
            cur += a[i];
            if (cur == rem) {
                pos = i;
                break;
            }
        }

        if (pos == -1) {
            long long cur2 = 0;
            for (int i = 0; i < T; i++) {
                cur2 += a[i];
                if (cur2 == rem + sum) {
                    pos = i;
                    q += 1;
                    break;
                }
                if ((sum < 0 && cur2 < rem + sum) || (sum > 0 && cur2 > rem + sum)) {
                    break;
                }
            }
        }

        if (pos == -1) {
            cout << "Esse numero deve estar errado...\n";
            return 0;
        }
        cout << pos << " " << q << "\n";
    } else {
        cout << "Esse numero deve estar errado...\n";
    }

    return 0;
}