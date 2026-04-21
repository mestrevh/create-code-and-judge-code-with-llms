/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

static int parent[100005];
static int sz[100005];

int find_set(int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find_set(parent[i]);
}

void unite_sets(int i, int j) {
    int root_i = find_set(i);
    int root_j = find_set(j);
    if (root_i != root_j) {
        if (sz[root_i] < sz[root_j]) {
            parent[root_i] = root_j;
            sz[root_j] += sz[root_i];
        } else {
            parent[root_j] = root_i;
            sz[root_i] += sz[root_j];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k)) return 0;

    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        sz[i] = 1;
    }

    char op;
    int u, v;
    for (int i = 0; i < k; ++i) {
        if (!(cin >> op >> u >> v)) break;
        if (op == 'F') {
            unite_sets(u, v);
        } else if (op == 'C') {
            if (find_set(u) == find_set(v)) {
                cout << "S\n";
            } else {
                cout << "N\n";
            }
        }
    }

    return 0;
}