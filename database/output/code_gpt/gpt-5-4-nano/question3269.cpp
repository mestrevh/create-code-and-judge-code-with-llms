/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int cnt = 0;
    int next[26];
    Node() { fill(next, next + 26, -1); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    if (!(cin >> N >> K)) return 0;

    vector<Node> trie;
    trie.reserve((size_t)N * 20 + 1);
    trie.emplace_back();

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        int cur = 0;
        for (char ch : s) {
            int c = ch - 'a';
            if (trie[cur].next[c] == -1) {
                trie[cur].next[c] = (int)trie.size();
                trie.emplace_back();
            }
            cur = trie[cur].next[c];
            trie[cur].cnt++;
        }
    }

    vector<string> ans;
    string cur;

    function<void(int)> dfs = [&](int v) {
        if (v != 0 && trie[v].cnt >= K) ans.push_back(cur);
        for (int c = 0; c < 26; c++) {
            int u = trie[v].next[c];
            if (u == -1) continue;
            cur.push_back(char('a' + c));
            dfs(u);
            cur.pop_back();
        }
    };

    dfs(0);

    cout << ans.size() << "\n";
    for (auto &s : ans) cout << s << "\n";
    return 0;
}