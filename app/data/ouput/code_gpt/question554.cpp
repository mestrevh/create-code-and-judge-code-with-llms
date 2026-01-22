/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip>

using namespace std;

int findParent(int u, vector<int>& parent) {
    if (parent[u] != u) {
        parent[u] = findParent(parent[u], parent);
    }
    return parent[u];
}

void unionSets(int u, int v, vector<int>& parent, vector<int>& size) {
    int rootU = findParent(u, parent);
    int rootV = findParent(v, parent);
    if (rootU != rootV) {
        parent[rootU] = rootV;
        size[rootV] += size[rootU];
    }
}

int main() {
    int C;
    cin >> C;
    for (int caseNum = 1; caseNum <= C; ++caseNum) {
        int P, N;
        cin >> P >> N;
        
        vector<int> parent(P), size(P, 1);
        for (int i = 0; i < P; ++i) {
            parent[i] = i;
        }
        
        for (int i = 0; i < N; ++i) {
            int X, Y;
            cin >> X >> Y;
            unionSets(X, Y, parent, size);
        }
        
        map<int, int> categorySize;
        for (int i = 0; i < P; ++i) {
            int root = findParent(i, parent);
            categorySize[root]++;
        }
        
        int D = categorySize.size();
        int M = 0;
        for (const auto& pair : categorySize) {
            M = max(M, pair.second);
        }
        
        cout << "caso " << caseNum << ": " << D << " " << M << endl;
        
        if (caseNum < C) {
            cout << endl;
        }
    }
    return 0;
}
