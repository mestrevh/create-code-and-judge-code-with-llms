/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    while ( (cin >> N) ) {
        if (N == 0) break;
        vector<array<long long,3>> coord(N + 1);
        for (int i = 1; i <= N; i++) {
            long long x, y, z;
            cin >> x >> y >> z;
            coord[i] = {x, y, z};
        }

        vector<char> used(N + 1, 0);
        long long cx = 0, cy = 0, cz = 0;

        for (int step = 0; step < N; step++) {
            long long bestDist = -1;
            int bestId = -1;

            for (int i = 1; i <= N; i++) {
                if (used[i]) continue;
                long long dx = coord[i][0] - cx;
                long long dy = coord[i][1] - cy;
                long long dz = coord[i][2] - cz;
                long long dist = dx*dx + dy*dy + dz*dz;
                if (bestId == -1 || dist < bestDist || (dist == bestDist && i < bestId)) {
                    bestDist = dist;
                    bestId = i;
                }
            }

            used[bestId] = 1;
            cout << bestId << (step + 1 == N ? '\n' : ' ');
            cx = coord[bestId][0];
            cy = coord[bestId][1];
            cz = coord[bestId][2];
        }
    }
    return 0;
}