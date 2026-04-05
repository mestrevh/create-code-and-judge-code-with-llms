/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static inline bool hasAny(const vector<string>& v) {
    return !v.empty();
}

static vector<string> minimizeByLength(const vector<string>& v) {
    vector<string> r = v;
    sort(r.begin(), r.end(), [](const string& a, const string& b){
        if (a.size() != b.size()) return a.size() < b.size();
        return a < b;
    });
    r.erase(unique(r.begin(), r.end()), r.end());
    return r;
}

struct Trie {
    struct Node {
        int nxt[2];
        bool out;
        Node() : out(false) { nxt[0]=nxt[1]=-1; }
    };
    vector<Node> t;
    Trie() { t.emplace_back(); }
    void add(const string& s) {
        int cur = 0;
        for(char c: s) {
            int b = c - '0';
            if(t[cur].nxt[b] == -1) {
                t[cur].nxt[b] = (int)t.size();
                t.emplace_back();
            }
            cur = t[cur].nxt[b];
        }
        t[cur].out = true;
    }
};

static bool canMatchInfiniteOrFinite(const vector<string>& A, const vector<string>& B) {
    vector<string> a = minimizeByLength(A);
    vector<string> b = minimizeByLength(B);

    Trie ta, tb;
    for (auto &s: a) ta.add(s);
    for (auto &s: b) tb.add(s);

    int maxLenA = 0, maxLenB = 0;
    for (auto &s: a) maxLenA = max<int>(maxLenA, s.size());
    for (auto &s: b) maxLenB = max<int>(maxLenB, s.size());

    int LA = maxLenA, LB = maxLenB;
    int L = LA + LB;

    unordered_map<long long, int> dist;
    dist.reserve(1<<20);

    auto pack = [&](int i, int j)->long long{
        return ( (long long)i << 20 ) ^ (long long)j;
    };

    deque<pair<int,int>> q;
    int a0 = 0, b0 = 0;
    int startA = a0, startB = b0;

    long long stKey = pack(startA, startB);
    dist[stKey] = 0;
    q.push_back({startA, startB});

    while(!q.empty()) {
        auto [u, v] = q.front();
        q.pop_front();
        int d = dist[pack(u,v)];

        if (ta.t[u].out && tb.t[v].out) return true;

        if (d >= L) continue;

        for(int bit=0; bit<=1; bit++) {
            int nu = -1;
            if (ta.t[u].nxt[bit] != -1) nu = ta.t[u].nxt[bit];
            else nu = -1;

            int nv = -1;
            if (tb.t[v].nxt[bit] != -1) nv = tb.t[v].nxt[bit];
            else nv = -1;

            if (nu != -1 && nv != -1) {
                if (ta.t[nu].out) nu = 0;
                if (tb.t[nv].out) nv = 0;
                long long key = pack(nu, nv);
                if (!dist.count(key)) {
                    dist[key] = d+1;
                    q.push_back({nu, nv});
                }
            } else {
                if (nu == -1 || nv == -1) continue;
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N1, N2;
    bool firstOutput = true;
    while ( (cin >> N1 >> N2) ) {
        vector<string> A(N1), B(N2);
        for(int i=0;i<N1;i++) cin >> A[i];
        for(int i=0;i<N2;i++) cin >> B[i];

        A = minimizeByLength(A);
        B = minimizeByLength(B);

        bool ans = canMatchInfiniteOrFinite(A, B);

        cout << (ans ? 'S' : 'N') << "\n";
    }
    return 0;
}