/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> parent;

int find(int u) {
    if (parent[u] != u) 
        parent[u] = find(parent[u]);
    return parent[u];
}

void unionSets(int u, int v) {
    int pu = find(u);
    int pv = find(v);
    if (pu != pv) 
        parent[pu] = pv;
}

int main() {
    int N, M;
    cin >> N >> M;

    parent.resize(N + 1);
    for (int i = 1; i <= N; ++i)
        parent[i] = i;

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        unionSets(a, b);
    }

    int count = 0;
    for (int i = 1; i <= N; ++i) {
        if (parent[i] == i) 
            count++;
    }
    
    cout << count << endl;
    return 0;
}
