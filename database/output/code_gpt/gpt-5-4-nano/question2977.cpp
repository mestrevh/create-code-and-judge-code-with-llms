/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    while ( (cin >> n) ) {
        if (n == 0) break;
        const int MAXC = 500;
        vector<array<int,4>> rects;
        rects.reserve(n);
        for (int i = 0; i < n; i++) {
            int a,b,c,d;
            cin >> a >> b >> c >> d;
            rects.push_back({a,b,c,d});
        }

        int W = MAXC + 1;
        int H = MAXC + 1;
        int gridW = W;
        int gridH = H;

        vector<vector<int>> diff(gridW + 2, vector<int>(gridH + 2, 0));

        for (auto &r : rects) {
            int a=r[0], b=r[1], c=r[2], d=r[3];
            if (a < 0) a = 0;
            if (b < 0) b = 0;
            if (c > MAXC+1) c = MAXC+1;
            if (d > MAXC+1) d = MAXC+1;
            if (a >= c || b >= d) continue;
            diff[a][b] += 1;
            diff[c][b] -= 1;
            diff[a][d] -= 1;
            diff[c][d] += 1;
        }

        long long ans = 0;
        for (int x = 0; x <= MAXC; x++) {
            for (int y = 0; y <= MAXC; y++) {
                int val = diff[x][y];
                if (x > 0) val += diff[x-1][y];
                if (y > 0) val += diff[x][y-1];
                if (x > 0 && y > 0) val -= diff[x-1][y-1];
                diff[x][y] = val;
                if (x < MAXC && y < MAXC) {
                    if (val > 0) ans++;
                }
            }
        }

        cout << ans << "\n";
    }
    return 0;
}