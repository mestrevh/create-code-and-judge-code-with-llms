/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 1000005;
int L[MAXN];
int R[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, r;
    if (!(cin >> n >> k >> r)) return 0;

    for (int i = 0; i < n; ++i) {
        L[i] = -1;
        R[i] = -1;
    }

    for (int i = 0; i < k; ++i) {
        int s, l_child, r_child;
        if (cin >> s >> l_child >> r_child) {
            if (s >= 0 && s < n) {
                L[s] = l_child;
                R[s] = r_child;
            }
        }
    }

    queue<int> q;
    if (n > 0 && r >= 0 && r < n) {
        q.push(r);
    }

    int height = 0;
    while (!q.empty()) {
        int level_size = q.size();
        height++;
        for (int i = 0; i < level_size; ++i) {
            int u = q.front();
            q.pop();

            if (L[u] != -1 && L[u] >= 0 && L[u] < n) {
                q.push(L[u]);
            }
            if (R[u] != -1 && R[u] >= 0 && R[u] < n) {
                q.push(R[u]);
            }
        }
    }

    cout << height << endl;

    return 0;
}