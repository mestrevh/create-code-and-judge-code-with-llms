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
    while ( (cin >> n) ) {
        map<string, int> id;
        vector<string> names;
        vector<vector<int>> adj;
        vector<int> outdeg;

        auto getId = [&](const string& s) -> int {
            auto it = id.find(s);
            if (it != id.end()) return it->second;
            int idx = (int)names.size();
            id[s] = idx;
            names.push_back(s);
            adj.push_back({});
            outdeg.push_back(0);
            return idx;
        };

        for (int i = 0; i < n; i++) {
            string A, B;
            cin >> A >> B;
            int u = getId(A);
            int v = getId(B);
            adj[u].push_back(v);
            outdeg[u]++;
        }

        int N = (int)names.size();
        vector<int> removed(N, 0);
        vector<int> remainingOutdeg = outdeg;

        set<int> leaves;
        for (int i = 0; i < N; i++) {
            if (remainingOutdeg[i] == 0) leaves.insert(i);
        }

        auto cmpName = [&](int i, int j) {
            return names[i] < names[j];
        };

        struct Cmp {
            const vector<string>* p;
            Cmp(const vector<string>* pp=nullptr): p(pp) {}
            bool operator()(int a, int b) const {
                return (*p)[a] < (*p)[b];
            }
        };

        set<int, function<bool(int,int)>> orderedLeaves([&](int a, int b){
            return names[a] < names[b];
        });

        orderedLeaves = decltype(orderedLeaves)([&](int a, int b){
            return names[a] < names[b];
        });

        for (int i = 0; i < N; i++) {
            if (remainingOutdeg[i] == 0) orderedLeaves.insert(i);
        }

        bool first = true;
        while (!orderedLeaves.empty()) {
            vector<int> currentLeaves;
            currentLeaves.reserve(orderedLeaves.size());
            int lastPrinted = -1;

            while (!orderedLeaves.empty()) {
                int u = *orderedLeaves.begin();
                orderedLeaves.erase(orderedLeaves.begin());
                currentLeaves.push_back(u);
            }

            sort(currentLeaves.begin(), currentLeaves.end(), [&](int a, int b){
                return names[a] < names[b];
            });

            for (int u : currentLeaves) {
                cout << names[u] << "\n";
                removed[u] = 1;
                for (int v = 0; v < N; v++) {} 
            }

            for (int u : currentLeaves) {
                for (int v : adj[u]) {
                    if (removed[v]) continue;
                    remainingOutdeg[v]--;
                }
            }

            for (int i = 0; i < N; i++) {
                if (!removed[i] && remainingOutdeg[i] == 0) orderedLeaves.insert(i);
            }
        }
    }

    return 0;
}