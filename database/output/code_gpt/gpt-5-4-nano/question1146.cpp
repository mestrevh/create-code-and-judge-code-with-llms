/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, L;
    if (!(cin >> H >> L)) return 0;
    vector<vector<int>> a(H, vector<int>(L));
    for (int i = 0; i < H; i++) for (int j = 0; j < L; j++) cin >> a[i][j];

    vector<vector<int>> comp(H, vector<int>(L, -1));
    vector<int> compColor;
    vector<int> compSize;

    int n = 0;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < L; j++) {
            if (comp[i][j] != -1) continue;
            int c = a[i][j];
            queue<pair<int,int>> q;
            q.push({i,j});
            comp[i][j] = n;
            int sz = 0;
            while (!q.empty()) {
                auto [x,y] = q.front(); q.pop();
                sz++;
                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k], ny = y + dy[k];
                    if (nx < 0 || nx >= H || ny < 0 || ny >= L) continue;
                    if (comp[nx][ny] != -1) continue;
                    if (a[nx][ny] != c) continue;
                    comp[nx][ny] = n;
                    q.push({nx, ny});
                }
            }
            compColor.push_back(c);
            compSize.push_back(sz);
            n++;
        }
    }

    unordered_map<int, int> best; 
    best.reserve(n * 2);

    for (int id = 0; id < n; id++) {
        int c = compColor[id];
        if (c == 0) continue;
        auto it = best.find(c);
        if (it == best.end()) best[c] = compSize[id];
        else it->second = min(it->second, compSize[id]);
    }

    int ans = INT_MAX;
    for (auto &kv : best) ans = min(ans, kv.second);

    int holeId = -1;
    for (int id = 0; id < n; id++) {
        if (compColor[id] == 0) {
            holeId = id;
            break;
        }
    }

    vector<int> holeComps;
    for (int id = 0; id < n; id++) if (compColor[id] == 0) holeComps.push_back(id);

    vector<int> isHole(n, 0);
    for (int id : holeComps) isHole[id] = 1;

    int holeTotal = 0;
    for (int id : holeComps) holeTotal += compSize[id];

    int maxColor = 0;
    for (int i = 0; i < H; i++) for (int j = 0; j < L; j++) maxColor = max(maxColor, a[i][j]);

    vector<int> touchesColorMin(H*L+5, INT_MAX);

    vector<int> presentColors;
    presentColors.reserve(n);
    vector<char> usedColor(maxColor + 1, 0);
    for (int id = 0; id < n; id++) {
        int c = compColor[id];
        if (c != 0 && !usedColor[c]) {
            usedColor[c] = 1;
            presentColors.push_back(c);
        }
    }

    vector<int> dx2[0]; 

    for (int id : holeComps) {
        (void)id;
    }

    for (int id = 0; id < n; id++) {
        if (!isHole[id]) continue;
        holeTotal += 0;
    }

    for (int id = 0; id < n; id++) {
        if (!isHole[id]) continue;
        (void)id;
    }

    unordered_set<int> holeAdjColors;
    holeAdjColors.reserve(n*2);

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < L; j++) {
            if (a[i][j] != 0) continue;
            int id0 = comp[i][j];
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k], ny = j + dy[k];
                if (nx < 0 || nx >= H || ny < 0 || ny >= L) continue;
                int c = a[nx][ny];
                if (c == 0) continue;
                holeAdjColors.insert(c);
            }
        }
    }

    for (int c : presentColors) {
        int candidate = INT_MAX;

        auto it = best.find(c);
        if (it != best.end()) candidate = min(candidate, it->second);

        int minHoleGroup = INT_MAX;
        for (int id = 0; id < n; id++) {
            if (!isHole[id]) continue;
            int sz = compSize[id];
            if (sz >= candidate) continue;
        }
        (void)minHoleGroup;

        int minMerged = INT_MAX;

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < L; j++) {
                if (a[i][j] != 0) continue;
                int cid = comp[i][j];
                int start = cid;
                (void)start;
            }
        }

        vector<char> visHole(n, 0);

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < L; j++) {
                if (a[i][j] != 0) continue;
                int hid = comp[i][j];
                if (visHole[hid]) continue;

                queue<int> q;
                q.push(hid);
                visHole[hid] = 1;

                int totalSize = 0;
                int boundaryMin = INT_MAX;
                vector<int> touched;
                touched.clear();

                while (!q.empty()) {
                    int cur = q.front(); q.pop();
                    totalSize += compSize[cur];
                    int anyColor = INT_MAX;

                    vector<int> cells;
                    (void)cells;

                    for (int x = 0; x < 0; x++) (void)x;
                }
            }
        }

        (void)minMerged;
        (void)candidate;
    }

    vector<vector<int>> holeCompAdj(n);
    for (int id = 0; id < n; id++) holeCompAdj[id].clear();

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < L; j++) {
            int id1 = comp[i][j];
            if (a[i][j] == 0) continue;
            for (int k = 0; k < 4; k++) {
                int ni = i + dx[k], nj = j + dy[k];
                if (ni < 0 || ni >= H || nj < 0 || nj >= L) continue;
                if (a[ni][nj] != 0) continue;
                int idH = comp[ni][nj];
                holeCompAdj[idH].push_back(id1);
            }
        }
    }

    for (int c : presentColors) {
        int curAns = INT_MAX;
        auto it = best.find(c);
        if (it != best.end()) curAns = min(curAns, it->second);

        vector<int> visitedHole(n, 0);
        for (int hid : holeComps) {
            if (visitedHole[hid]) continue;
            queue<int> q;
            q.push(hid);
            visitedHole[hid] = 1;

            int total = 0;
            bool connectedToC = false;

            while (!q.empty()) {
                int x = q.front(); q.pop();
                total += compSize[x];

                bool has = false;
                if (!holeCompAdj[x].empty()) {
                    for (int adjId : holeCompAdj[x]) {
                        if (compColor[adjId] == c) {
                            has = true;
                            break;
                        }
                    }
                }
                if (has) connectedToC = true;

                for (int i = 0; i < (int)holeComps.size(); i++) (void)i;
            }

            if (!connectedToC) {
                continue;
            }

            curAns = min(curAns, total);
        }

        ans = min(ans, curAns);
    }

    if (ans == INT_MAX) ans = 0;
    cout << ans << "\n";
    return 0;
}