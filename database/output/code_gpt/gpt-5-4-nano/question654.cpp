/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to;
    int len;
    char first;
};

struct WordInfo {
    int to;
    int len;
    char first;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M;
    while ( (cin >> M) ) {
        if (M == 0) break;

        string O, D;
        cin >> O >> D;

        unordered_map<string,int> id;
        id.reserve((size_t)M*2 + 10);
        auto getId = [&](const string& s)->int{
            auto it = id.find(s);
            if(it != id.end()) return it->second;
            int nid = (int)id.size();
            id.emplace(s, nid);
            return nid;
        };

        int oId = getId(O);
        int dId = getId(D);

        vector<string> words; words.reserve(M);
        vector<tuple<string,string,string>> triples;
        triples.reserve(M);

        for(int i=0;i<M;i++){
            string a,b,p;
            cin >> a >> b >> p;
            int ia = getId(a);
            int ib = getId(b);
            (void)ia; (void)ib;
            triples.emplace_back(a,b,p);
        }

        int N = (int)id.size();

        vector<vector<Edge>> adj(N);
        unordered_set<string> used;
        used.reserve((size_t)M*2 + 10);

        auto addEdge = [&](int u, int v, const string& w){
            Edge e{v, (int)w.size(), w[0]};
            adj[u].push_back(e);
        };

        for (auto &t : triples) {
            string a, b, p;
            tie(a,b,p) = t;
            int ia = id[a];
            int ib = id[b];
            addEdge(ia, ib, p);
        }

        const int INF = 1e9;
        vector<int> dist(N*(N+1), INF);
        vector<int> prevNode(N*(N+1), -1);
        vector<int> prevState(N*(N+1), -1);

        vector<vector<int>> bestLen(N, vector<int>(26, INF));
        vector<vector<int>> bestEdgeIdx(N, vector<int>(26, -1));

        auto stateIndex = [&](int lang, int lastCharIndex)->int{
            return lang*(N+1) + (lastCharIndex+1);
        };

        int startCharIndex = -1;
        int startState = stateIndex(oId, -1);
        dist[startState] = 0;

        using PQItem = pair<int,int>;
        priority_queue<PQItem, vector<PQItem>, greater<PQItem>> pq;
        pq.push({0, startState});

        int answer = INF;

        while(!pq.empty()){
            auto [cd, st] = pq.top(); pq.pop();
            if (cd != dist[st]) continue;

            int lang = st/(N+1);
            int lastChar = st%(N+1) - 1;

            if (lang == dId) {
                answer = min(answer, cd);
            }

            for (auto &e : adj[lang]) {
                int nc = (int)e.first - (int)'a';
                if (lastChar != -1 && nc == lastChar) continue;
                int nst = stateIndex(e.to, nc);
                int nd = cd + e.len;
                if (nd < dist[nst]) {
                    dist[nst] = nd;
                    pq.push({nd, nst});
                }
            }
        }

        if (answer == INF) {
            cout << "impossivel\n";
        } else {
            cout << answer << "\n";
        }
    }
    return 0;
}