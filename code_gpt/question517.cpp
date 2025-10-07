/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

struct UnionFind {
    vector<int> parent, rank;

    UnionFind(int size) {
        parent.resize(size);
        rank.resize(size, 0);
        for (int i = 0; i < size; i++) parent[i] = i;
    }

    int find(int u) {
        if (parent[u] != u) parent[u] = find(parent[u]);
        return parent[u];
    }

    void unionSets(int u, int v) {
        u = find(u);
        v = find(v);
        if (u != v) {
            if (rank[u] < rank[v]) swap(u, v);
            parent[v] = u;
            if (rank[u] == rank[v]) rank[u]++;
        }
    }
};

int main() {
    string line;
    while (getline(cin, line) && !line.empty()) {
        stringstream ss(line);
        int N, M, Q;
        ss >> N >> M >> Q;

        UnionFind uf(N * N);
        vector<bool> walls(2 * (N * N - N), true);
        
        for (int i = 0; i < M; i++) {
            int w;
            cin >> w;
            walls[w] = false;
        }
        
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) {
                int cell = i * N + j;
                if (j < N - 1 && walls[i * (N - 1) + j]) uf.unionSets(cell, cell + 1);
                if (i < N - 1 && walls[N * (N - 1) + i * N + j]) uf.unionSets(cell, cell + N);
            }

        for (int i = 0; i < Q; i++) {
            int A, B;
            cin >> A >> B;
            cout << (uf.find(A) == uf.find(B));
            if (i < Q - 1) cout << endl;
        }

        cout << endl;
        cin.ignore();
    }
    return 0;
}
