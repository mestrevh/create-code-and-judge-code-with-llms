/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int parent[1005];

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b, int &components) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        parent[b] = a;
        components--;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    int components = N;
    for (int k = 0; k < M; k++) {
        int u, v;
        if (cin >> u >> v) {
            if (u >= 1 && u <= N && v >= 1 && v <= N) {
                union_sets(u, v, components);
            }
        }
    }

    cout << components << endl;

    return 0;
}