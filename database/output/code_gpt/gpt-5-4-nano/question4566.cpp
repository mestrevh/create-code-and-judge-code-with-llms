/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<char> letters(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        letters[i] = s[0];
    }

    int m;
    cin >> m;
    vector<long long> nums(m);
    for (int i = 0; i < m; i++) cin >> nums[i];

    int len = max(n, m);
    string out;
    out.reserve(len * 2);

    for (int i = 0; i < len; i++) {
        char res;
        if (i < n && i < m) {
            int shift = (int)nums[i];
            char base = letters[i];
            int pos = (base - 'a');
            int newpos = pos + shift;
            if (newpos < 0 || newpos > 25) res = '.';
            else res = char('a' + newpos);
        } else if (i < n) {
            res = letters[i];
        } else {
            int shift = (int)nums[i];
            int newpos = shift;
            if (newpos < 0 || newpos > 25) res = '.';
            else res = char('a' + newpos);
        }

        if (i) out.push_back(' ');
        out.push_back(res);
    }

    cout << out;
    return 0;
}