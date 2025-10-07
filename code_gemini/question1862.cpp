/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <functional>

using namespace std;

int M, R;
vector<vector<int>> H;
vector<vector<array<bool, 4>>> walls;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const char d_char[] = {'N', 'L', 'S', 'O'};

int best_radius_h;
int best_radius_x, best_radius_y;
string path_to_best_radius;

int global_max_h;
string path_to_global_max;
vector<vector<bool>> visited_global;

void solve1(int startX, int startY) {
    string path = "";
    int currentX = startX;
    int currentY = startY;

    while (true) {
        int best_h = H[currentX][currentY];
        int nextX = currentX;
        int nextY = currentY;
        int move_dir_idx = -1;

        for (int i = 0; i < 4; ++i) {
            int nx = currentX + dx[i];
            int ny = currentY + dy[i];

            if (nx >= 0 && nx < M && ny >= 0 && ny < M && !walls[currentX][currentY][i]) {
                if (H[nx][ny] > best_h) {
                    best_h = H[nx][ny];
                    nextX = nx;
                    nextY = ny;
                    move_dir_idx = i;
                }
            }
        }

        if (nextX == currentX && nextY == currentY) {
            break;
        }

        path += d_char[move_dir_idx];
        currentX = nextX;
        currentY = nextY;
    }

    cout << path << "=" << H[currentX][currentY] << endl;
}


void explore_paths_rec(int x, int y, int depth, const string& path) {
    if (depth == R) return;

    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < M && ny >= 0 && ny < M && !walls[x][y][i]) {
            string new_path = path + d_char[i];
            if (H[nx][ny] > best_radius_h) {
                best_radius_h = H[nx][ny];
                best_radius_x = nx;
                best_radius_y = ny;
                path_to_best_radius = new_path;
            }
            explore_paths_rec(nx, ny, depth + 1, new_path);
        }
    }
}

void solve2(int startX, int startY) {
    string total_path = "";
    int currentX = startX;
    int currentY = startY;

    while (true) {
        best_radius_h = H[currentX][currentY];
        best_radius_x = currentX;
        best_radius_y = currentY;
        path_to_best_radius = "";

        explore_paths_rec(currentX, currentY, 0, "");

        if (best_radius_x == currentX && best_radius_y == currentY) {
            break;
        }

        total_path += path_to_best_radius;
        currentX = best_radius_x;
        currentY = best_radius_y;
    }
    cout << total_path << "=" << H[currentX][currentY] << endl;
}


void dfs_global(int x, int y, const string& current_path) {
    visited_global[x][y] = true;

    if (H[x][y] > global_max_h) {
        global_max_h = H[x][y];
        path_to_global_max = current_path;
    }

    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < M && ny >= 0 && ny < M && !walls[x][y][i] && !visited_global[nx][ny]) {
            dfs_global(nx, ny, current_path + d_char[i]);
        }
    }
}

void solve3(int startX, int startY) {
    visited_global.assign(M, vector<bool>(M, false));
    global_max_h = -1;
    path_to_global_max = "";

    dfs_global(startX, startY, "");

    cout << path_to_global_max << "=" << global_max_h << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> M)) {
        return 0;
    }

    H.assign(M, vector<int>(M));
    for (int y = 0; y < M; ++y) {
        for (int x = 0; x < M; ++x) {
            cin >> H[x][y];
        }
    }

    walls.assign(M, vector<array<bool, 4>>(M, {false, false, false, false}));
    int W;
    cin >> W;
    for (int i = 0; i < W; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2) {
            walls[x1][y1][0] = true;
            walls[x2][y2][2] = true;
        } else {
            walls[x1][y1][1] = true;
            walls[x2][y2][3] = true;
        }
    }

    cin >> R;

    int K;
    cin >> K;

    for (int j = 0; j < K; ++j) {
        int x0, y0;
        cin >> x0 >> y0;

        cout << "caso " << j << ":" << endl;
        solve1(x0, y0);
        solve2(x0, y0);
        solve3(x0, y0);

        if (j < K - 1) {
            cout << endl;
        }
    }

    return 0;
}
