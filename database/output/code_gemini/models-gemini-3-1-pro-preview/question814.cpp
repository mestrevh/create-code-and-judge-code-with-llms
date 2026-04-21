/*
Código criado pelo models/gemini-3.1-pro-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int parent_node[7];

int find_set(int v) {
    if (v == parent_node[v])
        return v;
    return parent_node[v] = find_set(parent_node[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b)
        parent_node[b] = a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int test_case = 1;

    while (cin >> n && n != 0) {
        for (int i = 0; i < 7; i++) {
            parent_node[i] = i;
        }

        int degree[7] = {0};
        bool has_edge[7] = {false};

        for (int i = 0; i < n; i++) {
            int u, v;
            cin >> u >> v;
            degree[u]++;
            degree[v]++;
            has_edge[u] = true;
            has_edge[v] = true;
            union_sets(u, v);
        }

        int odd_count = 0;
        for (int i = 0; i < 7; i++) {
            if (degree[i] % 2 != 0) {
                odd_count++;
            }
        }

        int components = 0;
        for (int i = 0; i < 7; i++) {
            if (has_edge[i] && parent_node[i] == i) {
                components++;
            }
        }

        bool possible = true;
        if (odd_count != 0 && odd_count != 2) {
            possible = false;
        }
        if (components > 1) {
            possible = false;
        }

        cout << "Teste " << test_case++ << "\n";
        if (possible) {
            cout << "sim\n\n";
        } else {
            cout << "nao\n\n";
        }
    }

    return 0;
}