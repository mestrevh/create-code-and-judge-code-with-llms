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
    while (cin >> x) a.push_back(x);
    int n = (int)a.size();
    if (n == 0) return 0;

    long long mn = *min_element(a.begin(), a.end());
    long long mx = *max_element(a.begin(), a.end());
    long long bestVal = a[0];
    long long bestDiff2 = llabs((__int128)2 * a[0] - (__int128)mn - (__int128)mx);

    for (long long v : a) {
        long long diff2 = llabs((__int128)2 * v - (__int128)mn - (__int128)mx);
        if (diff2 < bestDiff2 || (diff2 == bestDiff2 && v < bestVal)) {
            bestDiff2 = diff2;
            bestVal = v;
        }
    }

    int pivotIndex = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == bestVal) {
            pivotIndex = i;
            break;
        }
    }

    vector<long long> left, right, middle;
    for (int i = 0; i < n; i++) {
        if (a[i] < bestVal) left.push_back(a[i]);
        else if (a[i] > bestVal) right.push_back(a[i]);
        else middle.push_back(a[i]);
    }

    long long pivot = bestVal;

    vector<long long> res;
    res.reserve(n);

    res.insert(res.end(), left.begin(), left.end());
    int midPos = (int)left.size();
    res.push_back(pivot);
    for (int i = 0; i < (int)middle.size() - 1; i++) res.push_back(middle[i + 1]);

    res.insert(res.end(), right.begin(), right.end());

    for (int i = 0; i < n; i++) {
        if (i) cout << ' ';
        cout << res[i];
    }
    cout << "\n";

    return 0;
}