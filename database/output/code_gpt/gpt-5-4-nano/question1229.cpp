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

    vector<long long> pool;
    pool.reserve(n + 5);

    unordered_map<long long, int> idx;
    idx.reserve((size_t)n * 2 + 10);

    long long x;
    for (int i = 0; i < n; i++) {
        string op;
        cin >> op;
        if (op == "i") {
            long long v;
            cin >> v;
            if (!idx.count(v)) {
                idx[v] = (int)pool.size();
                pool.push_back(v);
            }
        }
    }

    vector<int> parent(pool.size());
    vector<int> sz(pool.size());
    for (int i = 0; i < (int)pool.size(); i++) {
        parent[i] = i;
        sz[i] = 1;
    }

    function<int(int)> findp = [&](int a) -> int {
        if (parent[a] == a) return a;
        return parent[a] = findp(parent[a]);
    };

    auto unite = [&](int a, int b) {
        a = findp(a); b = findp(b);
        if (a == b) return a;
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        return a;
    };

    for (int i = 0; i < n; i++) {
        string op;
        cin >> op;
        if (op == "c") {
            long long k;
            cin >> k;
            int last = -1;
            for (int j = 0; j < k; j++) {
                long long v;
                cin >> v;
                if (!idx.count(v)) {
                    idx[v] = (int)pool.size();
                    pool.push_back(v);
                    parent.push_back((int)pool.size() - 1);
                    sz.push_back(1);
                }
                int id = idx[v];
                if (last != -1) unite(last, id);
                last = id;
            }
        } else if (op == "i") {
            long long v;
            cin >> v;
        } else if (op == "r") {
            continue;
        }
    }

    cin.clear();
    cin.seekg(0);

    vector<vector<long long>> stacks;
    stacks.reserve(n + 5);

    vector<int> topIndex(pool.size(), -1);

    int stacksCount = 0;
    auto ensureStack = [&](int s) {
        while ((int)stacks.size() <= s) stacks.push_back({});
    };

    vector<int> inStack(pool.size(), -1);

    cin.seekg(0);
    cin >> n;

    for (int i = 0; i < n; i++) {
        string op;
        cin >> op;
        if (op == "c") {
            long long k;
            cin >> k;
            stacks.push_back({});
            int sidx = (int)stacks.size() - 1;
            stacksCount++;

            vector<long long> vals;
            vals.reserve((size_t)k);
            for (int j = 0; j < k; j++) {
                long long v;
                cin >> v;
                if (!idx.count(v)) {
                    idx[v] = (int)pool.size();
                    pool.push_back(v);
                    parent.push_back((int)pool.size() - 1);
                    sz.push_back(1);
                }
                int id = idx[v];
                inStack[id] = sidx;
                vals.push_back(v);
            }
            for (long long v : vals) stacks[sidx].push_back(v);
            cout << "Conjunto de pilhas:\n";
            cout << "pilha:\n";
            for (int t = 0; t < (int)stacks[sidx].size(); t++) {
                cout << (t ? " " : "") << stacks[sidx][t];
            }
            cout << "\n\n";
        } else if (op == "i") {
            long long v;
            cin >> v;
            if (!idx.count(v)) {
                idx[v] = (int)pool.size();
                pool.push_back(v);
            }
            int id = idx[v];

            int sidx = (inStack[id] == -1 ? -1 : inStack[id]);
            if (sidx == -1) {
                stacks.push_back({});
                sidx = (int)stacks.size() - 1;
                stacksCount++;
                inStack[id] = sidx;
                stacks[sidx].push_back(v);
            } else {
                stacks[sidx].push_back(v);
                inStack[id] = sidx;
            }
            cout << "Conjunto de pilhas:\n";
            cout << "pilha:\n";
            for (int j = 0; j < (int)stacks[sidx].size(); j++) {
                cout << (j ? " " : "") << stacks[sidx][j];
            }
            cout << "\n\n";
        } else if (op == "r") {
            if (!stacks.empty()) {
                int lastNonEmpty = -1;
                for (int s = (int)stacks.size() - 1; s >= 0; s--) {
                    if (!stacks[s].empty()) {
                        lastNonEmpty = s;
                        break;
                    }
                }
                if (lastNonEmpty != -1) {
                    long long v = stacks[lastNonEmpty].back();
                    stacks[lastNonEmpty].pop_back();
                    if (!idx.count(v)) {
                    } else {
                        int id = idx[v];
                        inStack[id] = -1;
                    }
                    if (stacks[lastNonEmpty].empty()) {
                        bool any = false;
                        for (auto &st : stacks) if (!st.empty()) { any = true; break; }
                        cout << "Conjunto de pilhas:\n";
                        if (!any) {
                            cout << "conjunto de pilhas vazio!\n\n";
                        } else {
                            cout << "pilha:\n";
                            bool firstStackOutput = true;
                            for (auto &st : stacks) {
                                if (st.empty()) continue;
                                if (!firstStackOutput) cout << "pilha:\n";
                                firstStackOutput = false;
                                for (int j = 0; j < (int)st.size(); j++) cout << (j ? " " : "") << st[j];
                                cout << "\n";
                            }
                            cout << "\n";
                        }
                    } else {
                        cout << "Conjunto de pilhas:\n";
                        cout << "pilha:\n";
                        for (int j = 0; j < (int)stacks[lastNonEmpty].size(); j++) {
                            cout << (j ? " " : "") << stacks[lastNonEmpty][j];
                        }
                        cout << "\n\n";
                    }
                } else {
                    cout << "Conjunto de pilhas:\n";
                    cout << "conjunto de pilhas vazio!\n\n";
                }
            } else {
                cout << "Conjunto de pilhas:\n";
                cout << "conjunto de pilhas vazio!\n\n";
            }
        }
    }

    return 0;
}