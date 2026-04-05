/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    unordered_set<int> distinct;
    distinct.reserve(N * 2);

    long long high = 0, mid = 0, low = 0;
    int mn = INT_MAX, mx = INT_MIN;

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        distinct.insert(a);
        mn = min(mn, a);
        mx = max(mx, a);

        if (a >= 100) high++;
        else if (a >= 50) mid++;
        else low++;
    }

    cout << distinct.size() << "\n";
    cout << high << "\n";
    cout << mid << "\n";
    cout << low << "\n";
    cout << (mx - mn) << "\n";

    return 0;
}