/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Z, Y, X;
    if (!(cin >> Z >> Y >> X)) return 0;

    vector<vector<string>> grid(Z, vector<string>(Y));
    for (int z = 0; z < Z; z++) {
        for (int y = 0; y < Y; y++) {
            cin >> grid[z][y];
        }
    }

    auto inside = [&](int z, int y, int x) {
        return z >= 0 && z < Z && y >= 0 && y < Y && x >= 0 && x < X;
    };

    struct Prev { int pz, py, px; char mv; };
    const int INF = 1e9;
    vector<int> dist(Z * Y * X, INF);
    vector<Prev> prev(Z * Y * X, {-1, -1, -1, '?'});

    auto id = [&](int z, int y, int x) { return (z * Y + y) * X + x; };

    queue<tuple<int,int,int>> q;

    int sz = 0, sy = 0, sx = 0;
    int tz = Z - 1, ty = Y - 1, tx = X - 1;

    vector<tuple<int,int,int,char>> moves;
    moves.push_back({0, -1, 0, 'U'});
    moves.push_back({0, 1, 0, 'D'});
    moves.push_back({-1, 0, 0, 'B'});
    moves.push_back({1, 0, 0, 'F'});
    moves.push_back({0, 0, -1, 'L'});
    moves.push_back({0, 0, 1, 'R'});

    dist[id(sz,sy,sx)] = 0;
    q.push({sz,sy,sx});

    while (!q.empty()) {
        auto [z,y,x] = q.front();
        q.pop();
        int cur = id(z,y,x);
        if (z == tz && y == ty && x == tx) break;

        for (auto [dz,dy,dx,ch] : moves) {
            int nz = z + dz, ny = y + dy, nx = x + dx;
            if (!inside(nz,ny,nx)) continue;
            if (grid[nz][ny][nx] == '#') continue;
            int nid = id(nz,ny,nx);
            if (dist[nid] != INF) continue;
            dist[nid] = dist[cur] + 1;
            prev[nid] = {z,y,x,ch};
            q.push({nz,ny,nx});
        }
    }

    int target = id(tz,ty,tx);
    vector<char> path;
    int cur = target;
    while (!(cur == id(sz,sy,sx))) {
        Prev pr = prev[cur];
        path.push_back(pr.mv);
        cur = id(pr.pz, pr.py, pr.px);
        if (cur < 0) break;
    }
    reverse(path.begin(), path.end());

    cout << path.size() << "\n";
    if (!path.empty()) {
        for (size_t i = 0; i < path.size(); i++) {
            if (i) cout << " -> ";
            cout << path[i];
        }
    }
    return 0;
}