/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int next[26];
    int cntEnd = 0;
    Node() { memset(next, -1, sizeof(next)); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<Node> trie;
    trie.reserve(2000000);
    trie.push_back(Node());

    long long totalWords = 0;
    long long totalKeys = 0;

    int N;
    while ( (cin >> N) ) {
        trie.clear();
        trie.push_back(Node());
        totalWords = N;
        totalKeys = 0;

        for (int i = 0; i < N; i++) {
            string s;
            cin >> s;
            int v = 0;
            for (char ch : s) {
                int c = ch - 'a';
                if (trie[v].next[c] == -1) {
                    trie[v].next[c] = (int)trie.size();
                    trie.push_back(Node());
                }
                v = trie[v].next[c];
            }
            trie[v].cntEnd++;
        }

        vector<int> childCount(trie.size(), 0);
        for (size_t v = 0; v < trie.size(); v++) {
            int cnt = 0;
            for (int c = 0; c < 26; c++) if (trie[v].next[c] != -1) cnt++;
            childCount[v] = cnt;
        }

        vector<int> good = childCount;
        for (size_t v = 0; v < trie.size(); v++) {
            good[v] = (childCount[v] == 1 && trie[v].cntEnd == 0) ? trie[v].next[ [=](){
                for (int c = 0; c < 26; c++) if (trie[v].next[c] != -1) return c;
                return 0;
            }()] : -1);
        }

        function<int(int)> compute = [&](int v) -> int {
            int needed = 0;
            int cur = v;
            while (true) {
                if (trie[cur].cntEnd > 0) break;
                if (childCount[cur] != 1) break;
                int c = -1;
                for (int i = 0; i < 26; i++) if (trie[cur].next[i] != -1) { c = i; break; }
                int nxt = trie[cur].next[c];
                if (trie[nxt].cntEnd > 0) break;
                needed++;
                cur = nxt;
            }
            return needed;
        };

        vector<int> memo(trie.size(), -1);
        function<int(int)> keysForPrefix = [&](int v) -> int {
            if (memo[v] != -1) return memo[v];
            int res = 0;
            if (trie[v].cntEnd > 0) {
                int remMin = INT_MAX;
                if (trie[v].cntEnd > 0) remMin = 0;
                for (int c = 0; c < 26; c++) {
                    int u = trie[v].next[c];
                    if (u == -1) continue;
                    int r = 1 + keysForPrefix(u);
                    remMin = min(remMin, r);
                }
                if (remMin == INT_MAX) remMin = 0;
                res = remMin;
            } else {
                if (childCount[v] == 0) res = 0;
                else {
                    int cnt = 0;
                    for (int c = 0; c < 26; c++) if (trie[v].next[c] != -1) { cnt++; break; }
                    if (childCount[v] == 1) {
                        int c = -1;
                        for (int i = 0; i < 26; i++) if (trie[v].next[i] != -1) { c = i; break; }
                        int u = trie[v].next[c];
                        if (trie[v].cntEnd == 0 && trie[v].cntEnd == 0) {
                            if (childCount[v] == 1) {
                                if (trie[v].cntEnd == 0) {
                                    if (trie[u].cntEnd == 0) {
                                        res = compute(v);
                                        res += 1 + keysForPrefix(u);
                                    } else {
                                        res = 1;
                                    }
                                }
                            }
                        }
                    }
                    if (res == 0) {
                        int remMin = INT_MAX;
                        for (int c = 0; c < 26; c++) {
                            int u = trie[v].next[c];
                            if (u == -1) continue;
                            int r = 1 + keysForPrefix(u);
                            remMin = min(remMin, r);
                        }
                        if (remMin == INT_MAX) remMin = 0;
                        res = remMin;
                    }
                }
            }
            memo[v] = res;
            return res;
        };

        vector<int> prefixDone(trie.size(), 0);
        vector<long long> sumKeysByNode(trie.size(), 0);

        function<void(int)> dfs = [&](int v) {
            for (int c = 0; c < 26; c++) {
                int u = trie[v].next[c];
                if (u == -1) continue;
                dfs(u);
            }
        };
        dfs(0);

        struct Frame { int v; };
        vector<int> prefixStates(trie.size(), 0);

        vector<long long> cntByNode(trie.size(), 0);
        function<void(int)> dfsCnt = [&](int v) {
            cntByNode[v] = trie[v].cntEnd;
            for (int c = 0; c < 26; c++) {
                int u = trie[v].next[c];
                if (u == -1) continue;
                dfsCnt(u);
                cntByNode[v] += cntByNode[u];
            }
        };
        dfsCnt(0);

        vector<long long> keysSumByNode(trie.size(), 0);

        function<void(int)> dfsKeys = [&](int v) {
            keysSumByNode[v] = 0;
            long long total = cntByNode[v];
            if (total == 0) return;

            if (trie[v].cntEnd > 0) {
                keysSumByNode[v] += 0LL * trie[v].cntEnd;
            }

            if (childCount[v] == 0) return;

            if (childCount[v] == 1 && trie[v].cntEnd == 0) {
                int c = -1;
                for (int i = 0; i < 26; i++) if (trie[v].next[i] != -1) { c = i; break; }
                int u = trie[v].next[c];
                dfsKeys(u);
                keysSumByNode[v] = keysSumByNode[u];
            } else {
                for (int c = 0; c < 26; c++) {
                    int u = trie[v].next[c];
                    if (u == -1) continue;
                    dfsKeys(u);
                    long long ways = cntByNode[u];
                    keysSumByNode[v] += ways + keysSumByNode[u];
                }
            }
        };

        function<void(int)> post = [&](int v) {
            for (int c = 0; c < 26; c++) {
                int u = trie[v].next[c];
                if (u == -1) continue;
                post(u);
            }
        };
        post(0);
        dfsKeys(0);

        long long numerator = 0;
        for (int c = 0; c < 26; c++) {
            int u = trie[0].next[c];
            if (u == -1) continue;
            long long ways = cntByNode[u];
            long long sum = keysSumByNode[u];
            numerator += ways + sum;
        }

        double ans = (double)numerator / (double)N;
        cout.setf(std::ios::fixed); 
        cout << setprecision(2) << ans + 1e-9 << "\n";
    }
    return 0;
}