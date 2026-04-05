/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct DSU {
    vector<int> parent;
    DSU() {}
    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; ++i) parent[i] = i;
    }
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) parent[root_i] = root_j;
    }
};

int M, L;
int total_empty;
vector<vector<int8_t>> status;
vector<vector<int>> PlotOwner;
vector<int> first_empty;
int K_to_pos[1048577];
DSU dsu;

void add_simple(int K) {
    int start_f = K % M;
    int f = dsu.find(start_f);
    
    int j = first_empty[f];
    status[f][j] = 1;
    PlotOwner[f][j] = K;
    K_to_pos[K] = f * L + j;
    first_empty[f]++;
    total_empty--;
    
    if (first_empty[f] == L) {
        dsu.unite(f, (f + 1) % M);
    }
}

void expand() {
    vector<int> bodies;
    for (int f = 0; f < M; ++f) {
        for (int j = 0; j < L; ++j) {
            if (status[f][j] == 1) {
                bodies.push_back(PlotOwner[f][j]);
            }
        }
    }
    
    M = 2 * M + 1;
    status.assign(M, vector<int8_t>(L, 0));
    PlotOwner.assign(M, vector<int>(L, 0));
    first_empty.assign(M, 0);
    total_empty = M * L;
    dsu = DSU(M);
    
    for (int k : bodies) {
        add_simple(k);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> M >> L)) return 0;
    
    for (int i = 0; i < 1048577; ++i) K_to_pos[i] = -1;

    status.assign(M, vector<int8_t>(L, 0));
    PlotOwner.assign(M, vector<int>(L, 0));
    first_empty.assign(M, 0);
    total_empty = M * L;
    dsu = DSU(M);

    string op;
    int K;
    int S = 0;
    while (cin >> op >> K) {
        if (op == "ADD") {
            if (total_empty == 0) {
                expand();
            }
            add_simple(K);
            int flat = K_to_pos[K];
            cout << S << " " << flat / L << "." << flat % L << "\n";
        } else if (op == "REM") {
            if (K < 0 || K > 1048576 || K_to_pos[K] == -1) {
                cout << S << " ?.?\n";
            } else {
                int flat = K_to_pos[K];
                int f = flat / L;
                int j = flat % L;
                status[f][j] = 2;
                K_to_pos[K] = -1;
                cout << S << " " << f << "." << j << "\n";
            }
        } else if (op == "QRY") {
            if (K < 0 || K > 1048576 || K_to_pos[K] == -1) {
                cout << S << " ?.?\n";
            } else {
                int flat = K_to_pos[K];
                cout << S << " " << flat / L << "." << flat % L << "\n";
            }
        }
        S++;
    }

    return 0;
}