/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int H = 5, W = 10;
    vector<string> grid(H);
    for (int i = 0; i < H; i++) {
        if (!(cin >> grid[i])) return 0;
        if ((int)grid[i].size() != W) {
            string s = grid[i];
            while ((int)s.size() < W && (cin >> ws, cin.peek() != EOF)) {
                string t;
                if (!(cin >> t)) break;
                s += t;
                if ((int)s.size() >= W) break;
            }
            grid[i] = s.substr(0, W);
        }
    }

    bool found = false;
    int bestX = -1, bestY = -1;
    long long bestTimeNum = -1;
    long long bestTopDist = -1;

    for (int r = 0; r < H; r++) {
        for (int c = 0; c < W; c++) {
            char ch = grid[r][c];
            if (ch != '0' && ch != '1') continue;
            bool on = (ch == '1');
            long long x = c, y = r;

            long long d2 = x * x + y * y;
            long long timeNum = 20 * d2 + (on ? 0 : 40) * (d2 == 0 ? 1 : d2);

            long long topDist = (H - 1 - r);

            if (!found) {
                found = true;
                bestX = c; bestY = r;
                bestTimeNum = timeNum;
                bestTopDist = topDist;
            } else {
                if (timeNum < bestTimeNum) {
                    bestX = c; bestY = r;
                    bestTimeNum = timeNum;
                    bestTopDist = topDist;
                } else if (timeNum == bestTimeNum) {
                    if (topDist > bestTopDist) {
                        bestX = c; bestY = r;
                        bestTopDist = topDist;
                    }
                }
            }
        }
    }

    if (!found) {
        cout << "Tristemente voce vai ter que aturar os PCs do grad 4";
    } else {
        cout << "Vai la pro computador " << bestX << " da fileira " << bestY;
    }
    return 0;
}