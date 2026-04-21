/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    if (!(cin >> n >> k)) return 0;
    vector<string> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int ansx = -1, ansy = -1;

    auto checkLine = [&](int sx, int sy, int dx, int dy) -> bool {
        int x = sx, y = sy;
        string s;
        s.reserve(k);
        for (int t = 0; t < k; t++) {
            if (x < 0 || x >= n || y < 0 || y >= n) return false;
            s.push_back(a[x][y]);
            x += dx; y += dy;
        }
        string r = s;
        reverse(r.begin(), r.end());
        return s == r;
    };

    int dirs[4][2] = {{0,1},{1,0},{1,1},{1,-1}};
    for (int i = 0; i < n && ansx == -1; i++) {
        for (int j = 0; j < n && ansx == -1; j++) {
            for (auto &d : dirs) {
                int dx = d[0], dy = d[1];
                int ex = i + (k - 1) * dx;
                int ey = j + (k - 1) * dy;
                if (ex < 0 || ex >= n || ey < 0 || ey >= n) continue;
                if (checkLine(i, j, dx, dy)) {
                    ansx = i;
                    ansy = j;
                    break;
                }
            }
        }
    }

    cout << "(" << ansx << ", " << ansy << ")\n";
    return 0;
}