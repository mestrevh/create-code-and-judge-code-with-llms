/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> a;
    long long x;
    if (!(cin >> x)) return 0;
    long long v;
    while (cin >> v) a.push_back(v);

    int n = (int)a.size();
    int l = 0, r = n - 1;
    int idx = -1;
    long long ops = 1;

    if (n > 0) {
        while (l <= r) {
            long long mid = (l + r) / 2;
            if (a[mid] == x) {
                idx = (int)mid;
                break;
            } else if (a[mid] < x) {
                l = (int)mid + 1;
            } else {
                r = (int)mid - 1;
            }
            ops++;
        }
    } else {
        idx = -1;
        ops = 1;
    }

    if (n == 0) cout << idx << "\n" << ops << "\n";
    else cout << idx << "\n" << ops << "\n";
    return 0;
}