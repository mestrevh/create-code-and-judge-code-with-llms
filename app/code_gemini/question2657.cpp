/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

int N_grid, M_grid;
vector<vector<int>> grid;
vector<vector<vector<bool>>> visited;
map<int, vector<pair<int, int>>> portal_locations;

bool solve_maze(int r, int c, int portals_left) {
    if (r < 0 || r >= N_grid || c < 0 || c >= M_grid) {
        return false;
    }
    if (grid[r][c] == 0) {
        return false;
    }
    if (visited[r][c][portals_left]) {
        return false;
    }

    if (r == N_grid - 1 && c == M_grid - 1) {
        return true;
    }

    visited[r][c][portals_left] = true;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    for (int i = 0; i < 4; ++i) {
        if (solve_maze(r + dr[i], c + dc[i], portals_left)) {
            return true;
        }
    }

    int cell_value = grid[r][c];
    if (cell_value > 1 && portals_left > 0) {
        if (portal_locations.count(cell_value) && portal_locations[cell_value].size() == 2) {
            pair<int, int> current_pos = {r, c};
            pair<int, int> target_pos;
            if (portal_locations[cell_value][0] == current_pos) {
                target_pos = portal_locations[cell_value][1];
            } else {
                target_pos = portal_locations[cell_value][0];
            }
            if (solve_maze(target_pos.first, target_pos.second, portals_left - 1)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n_hostages;
    cin >> n_hostages;

    map<int, int> claim_counts;
    for (int i = 0; i < n_hostages; ++i) {
        int claim;
        cin >> claim;
        claim_counts[claim]++;
    }

    int consistent_k_gt_zero = -1;
    for (int k = 1; k <= n_hostages; ++k) {
        if (claim_counts[k] == k) {
            consistent_k_gt_zero = k;
            break;
        }
    }

    if (consistent_k_gt_zero != -1) {
        cout << "Vamo nessa, temos que sair rapido..." << endl;
        
        int liars_for_maze = n_hostages - consistent_k_gt_zero;

        cin >> N_grid >> M_grid;
        grid.assign(N_grid, vector<int>(M_grid));
        portal_locations.clear();

        for (int i = 0; i < N_grid; ++i) {
            for (int j = 0; j < M_grid; ++j) {
                cin >> grid[i][j];
                if (grid[i][j] > 1) {
                    portal_locations[grid[i][j]].push_back({i, j});
                }
            }
        }

        if (N_grid > 0 && M_grid > 0) {
            visited.assign(N_grid, vector<vector<bool>>(M_grid, vector<bool>(n_hostages + 1, false)));
            
            if (solve_maze(0, 0, liars_for_maze)) {
                cout << "Tudo nosso" << endl;
            } else {
                cout << "Continuem cavando!" << endl;
            }
        } else {
             cout << "Continuem cavando!" << endl;
        }

    } else {
        cout << "Ja nao se pode confiar nos refens como antigamente..." << endl;
    }

    return 0;
}
