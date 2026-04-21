/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int centralC[10005], centralD[10005];
int memoC[10005], memoD[10005];

int getSpineC(int u) {
    if (u == 0) return 0;
    if (memoC[u] != -1) return memoC[u];
    return memoC[u] = 1 + getSpineC(centralC[u]);
}

int getSpineD(int v) {
    if (v == 0) return 0;
    if (memoD[v] != -1) return memoD[v];
    return memoD[v] = 1 + getSpineD(centralD[v]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    while (cin >> N) {
        for (int i = 0; i < 10005; ++i) {
            centralC[i] = 0;
            memoC[i] = -1;
        }

        vector<int> nodesC;
        for (int i = 0; i < N; ++i) {
            int id, l, k;
            cin >> id >> l >> k;
            centralC[id] = k;
            nodesC.push_back(id);
        }

        int M;
        cin >> M;
        for (int i = 0; i < 10005; ++i) {
            centralD[i] = 0;
            memoD[i] = -1;
        }

        vector<int> nodesD;
        for (int i = 0; i < M; ++i) {
            int id, q, r;
            cin >> id >> q >> r;
            centralD[id] = q;
            nodesD.push_back(id);
        }

        int maxOverlap = 0;
        int SD1 = getSpineD(1);
        for (int id : nodesC) {
            int currentOverlap = min(getSpineC(id), SD1);
            if (currentOverlap > maxOverlap) {
                maxOverlap = currentOverlap;
            }
        }

        int SC1 = getSpineC(1);
        for (int id : nodesD) {
            int currentOverlap = min(getSpineD(id), SC1);
            if (currentOverlap > maxOverlap) {
                maxOverlap = currentOverlap;
            }
        }

        cout << (N + M - maxOverlap) << "\n";
    }

    return 0;
}

