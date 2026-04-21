/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int M, R, K;
int H[105][105];
bool wall[105][105][4]; // 0:N, 1:L, 2:S, 3:O
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
char chars[] = {'N', 'L', 'S', 'O'};

string solve1(int x, int y) {
    string path = "";
    int curX = x, curY = y;
    while (true) {
        int bestH = H[curX][curY];
        int bestD = -1;
        for (int d = 0; d < 4; ++d) {
            int nx = curX + dx[d], ny = curY + dy[d];
            if (nx >= 0 && nx < M && ny >= 0 && ny < M && !wall[curX][curY][d]) {
                if (H[nx][ny] > bestH) {
                    bestH = H[nx][ny];
                    bestD = d;
                }
            }
        }
        if (bestD == -1) break;
        path += chars[bestD];
        curX += dx[bestD];
        curY += dy[bestD];
    }
    return path + "=" + to_string(H[curX][curY]);
}

int maxH2;
string bestP2;
int targetX2, targetY2;

void dfs2(int x, int y, int d, int maxDist, string path, bool vis[105][105]) {
    vis[x][y] = true;
    if (H[x][y] > maxH2) {
        maxH2 = H[x][y];
        bestP2 = path;
        targetX2 = x;
        targetY2 = y;
    }
    if (d < maxDist) {
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < M && ny >= 0 && ny < M && !wall[x][y][i] && !vis[nx][ny]) {
                dfs2(nx, ny, d + 1, maxDist, path + chars[i], vis);
            }
        }
    }
}

string solve2(int x, int y, int maxDist) {
    string totalPath = "";
    int curX = x, curY = y;
    while (true) {
        maxH2 = H[curX][curY];
        bestP2 = "";
        bool vis[105][105];
        memset(vis, 0, sizeof(vis));
        dfs2(curX, curY, 0, maxDist, "", vis);
        if (maxH2 > H[curX][curY]) {
            totalPath += bestP2;
            curX = targetX2;
            curY = targetY2;
        } else break;
    }
    return totalPath + "=" + to_string(H[curX][curY]);
}

int maxH3;
string bestP3;
bool vis3[105][105];

void dfs3(int x, int y, string path) {
    vis3[x][y] = true;
    if (H[x][y] > maxH3) {
        maxH3 = H[x][y];
        bestP3 = path;
    }
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < M && ny >= 0 && ny < M && !wall[x][y][i] && !vis3[nx][ny]) {
            dfs3(nx, ny, path + chars[i]);
        }
    }
}

string solve3(int x, int y) {
    maxH3 = -1;
    bestP3 = "";
    memset(vis3, 0, sizeof(vis3));
    dfs3(x, y, "");
    return bestP3 + "=" + to_string(maxH3);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (!(cin >> M)) return 0;
    for (int y = 0; y < M; ++y) {
        for (int x = 0; x < M; ++x) {
            cin >> H[x][y];
        }
    }
    int W;
    if (!(cin >> W)) W = 0;
    memset(wall, 0, sizeof(wall));
    for (int i = 0; i < W; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2 && y2 == y1 + 1) {
            wall[x1][y1][0] = true;
            wall[x2][y2][2] = true;
        } else if (y1 == y2 && x2 == x1 + 1) {
            wall[x1][y1][1] = true;
            wall[x2][y1][3] = true;
        }
    }
    if (!(cin >> R >> K)) return 0;
    for (int j = 0; j < K; ++j) {
        int x0, y0;
        cin >> x0 >> y0;
        cout << "caso " << j << ":" << endl;
        cout << solve1(x0, y0) << endl;
        cout << solve2(x0, y0, R) << endl;
        cout << solve3(x0, y0) << endl;
        cout << endl;
    }
    return 0;
}