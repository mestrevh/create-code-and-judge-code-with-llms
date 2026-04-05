/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!(cin >> s)) return 0;
    vector<long long> a;
    long long x;
    while (cin >> x) a.push_back(x);

    int n = (int)a.size();
    sort(a.begin(), a.end());

    vector<long long> ans(n);
    int pos = n - 1;

    vector<int> q;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == '<') q.push_back(i);
    }

    int i = 0;
    while (i < (int)s.size()) {
        if (s[i] == '<') {
            int j = i;
            while (j < (int)s.size() && s[j] == '<') j++;
            int L = j - i + 1;
            for (int k = 0; k < L; k++) ans[i + k] = a[n - 1 - (pos - (i + k))];
            pos -= L;
            for (int k = 0; k < L; k++) ans[i + k] = a[n - 1 - ( (n - 1 - (pos + L)) + k )];
            i = j;
        } else {
            i++;
        }
    }

    int L = (int)s.size();
    int idx = 0;
    vector<long long> res;
    res.reserve(n);

    int l = 0, r = n - 1;
    for (int i = 0; i < L; i++) {
        if (s[i] == '<') {
            res.push_back(a[l++]);
        } else {
            res.push_back(a[r--]);
        }
    }
    res.push_back(a[l]);
    for (int i = 0; i < n; i++) ans[i] = res[i];

    for (int i = 0; i < n; i++) {
        if (i) cout << ' ';
        cout << ans[i];
        if (i < n - 1) cout << ' ' << s[i];
    }
    return 0;
}