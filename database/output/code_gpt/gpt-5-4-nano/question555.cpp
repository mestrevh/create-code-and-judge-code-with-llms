/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int L;
    if (!(cin >> L)) return 0;

    string s;
    getline(cin, s);
    getline(cin, s);
    while (s.size() == 0 && !cin.eof()) getline(cin, s);

    vector<string> words;
    {
        string cur;
        for (size_t i = 0; i < s.size(); i++) {
            char c = s[i];
            if (isspace((unsigned char)c)) {
                if (!cur.empty()) {
                    words.push_back(cur);
                    cur.clear();
                }
            } else {
                cur.push_back(c);
            }
        }
        if (!cur.empty()) words.push_back(cur);
    }

    int n = (int)words.size();
    vector<int> len(n);
    for (int i = 0; i < n; i++) len[i] = (int)words[i].size();

    vector<int> nextIdx(n + 1, n);
    vector<int> spaces(n + 1, 0);
    for (int i = 0; i < n; i++) {
        int totalWordChars = 0;
        int k = i;
        while (k < n) {
            if (k == i) totalWordChars += len[k];
            else totalWordChars += 1 + len[k];
            if (totalWordChars > L) break;
            k++;
        }
        nextIdx[i] = k;
        int maxk = k;
        int totalChars = 0;
        for (int t = i; t < maxk; t++) totalChars += len[t];
        if (maxk > i) totalChars += (maxk - i - 1);
        int used = 0;
        used = 0;
        for (int t = i; t < maxk; t++) used += len[t];
        if (maxk > i) used += (maxk - i - 1);
        int lastSpaces = L - used;
        spaces[i] = lastSpaces;
    }

    vector<long long> dp(n + 1, (1LL<<62));
    vector<int> parent(n + 1, -1);
    dp[n] = 0;

    vector<long long> prefLen(n + 1, 0);
    for (int i = 0; i < n; i++) prefLen[i+1] = prefLen[i] + len[i];

    auto costLine = [&](int i, int j) -> long long {
        if (i > j) return (long long)0;
        int wordChars = prefLen[j+1] - prefLen[i];
        int gaps = (j - i);
        int used = wordChars + gaps;
        int rem = L - used;
        long long c = 1LL * rem * rem * rem;
        return c;
    };

    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            int wordChars = prefLen[j+1] - prefLen[i];
            int gaps = (j - i);
            int used = wordChars + gaps;
            if (used > L) break;
            long long c = costLine(i, j);
            long long cand = c + dp[j+1];
            if (cand < dp[i]) {
                dp[i] = cand;
                parent[i] = j;
            }
        }
    }

    int i = 0;
    while (i < n) {
        int j = parent[i];
        if (j < i) break;
        for (int k = i; k <= j; k++) {
            if (k > i) cout << ' ';
            cout << words[k];
        }
        cout << '\n';
        i = j + 1;
    }

    return 0;
}