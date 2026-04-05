/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 100005;
int parent[MAXN];
int rnk[MAXN];
ll bananas[MAXN];
ll component_sum[MAXN];

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void unite_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rnk[a] < rnk[b]) {
            parent[a] = b;
        } else {
            parent[b] = a;
            if (rnk[a] == rnk[b]) {
                rnk[a]++;
            }
        }
    }
}

void solve() {
    int N, M;
    if (!(cin >> N >> M)) return;
    
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        rnk[i] = 0;
        component_sum[i] = 0;
    }
    
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        if (u >= 1 && u <= N && v >= 1 && v <= N) {
            unite_sets(u, v);
        }
    }
    
    for (int i = 1; i <= N; i++) {
        cin >> bananas[i];
    }
    
    for (int i = 1; i <= N; i++) {
        component_sum[find_set(i)] += bananas[i];
    }
    
    ll max_bananas = 0;
    for (int i = 1; i <= N; i++) {
        if (component_sum[i] > max_bananas) {
            max_bananas = component_sum[i];
        }
    }
    
    cout << max_bananas << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    
    return 0;
}