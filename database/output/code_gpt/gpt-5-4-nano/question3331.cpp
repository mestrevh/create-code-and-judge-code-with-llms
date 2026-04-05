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

    sort(a.begin(), a.end());

    for (size_t i = 0; i < a.size(); i++) {
        cout << a[i] << ' ';
    }
    cout << "\n";

    unordered_map<long long, int> freq;
    freq.reserve(a.size() * 2 + 1);
    for (long long v : a) freq[v]++;

    long long ans = 0;
    for (auto &p : freq) {
        if (p.second % 2 == 1) {
            ans = p.first;
            break;
        }
    }

    cout << ans << "\n";
    return 0;
}