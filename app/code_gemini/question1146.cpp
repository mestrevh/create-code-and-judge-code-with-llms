/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>

using namespace std;

int H, L;
vector<vector<int>> grid;
vector<vector<int>> component_grid;
vector<pair<int, int>> component_info;
vector<vector<bool>> visited;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
        }
    }
};

bool is_valid(int r, int c) {
    return r >= 0 && r < H && c >= 0 && c < L;
}

void find_component_bfs(int start_r, int start_c, int comp_id) {
    int color = grid[start_r][start_c];
    int size = 0;
    queue<pair<int, int>> q;

    q.push({start_r, start_c});
    visited[start_r][start_c] = true;

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();
        int r = curr.first;
        int c = curr.second;

        component_grid[r][c] = comp_id;
        size++;

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (is_valid(nr, nc) && !visited[nr][nc] && grid[nr][nc] == color) {
                visited[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }
    component_info[comp_id] = {color, size};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> H >> L;

    grid.assign(H, vector<int>(L));
    set<int> unique_colors;
    bool has_holes = false;

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < L; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] != 0) {
                unique_colors.insert(grid[i][j]);
            } else {
                has_holes = true;
            }
        }
    }
    
    component_grid.assign(H, vector<int>(L, 0));
    visited.assign(H, vector<bool>(L, false));
    component_info.push_back({-1, -1});
    int comp_id_counter = 1;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < L; ++j) {
            if (!visited[i][j]) {
                component_info.resize(comp_id_counter + 1);
                find_component_bfs(i, j, comp_id_counter);
                comp_id_counter++;
            }
        }
    }

    if (!has_holes) {
        int min_area = H * L + 1;
        if (comp_id_counter > 1) {
            min_area = component_info[1].second;
        }
        for (int i = 2; i < comp_id_counter; ++i) {
            min_area = min(min_area, component_info[i].second);
        }
        cout << min_area << endl;
        return 0;
    }

    unique_colors.insert(40001);
    int global_min_area = H * L + 1;

    for (int test_color : unique_colors) {
        DSU dsu(comp_id_counter);
        
        for (int r = 0; r < H; ++r) {
            for (int c = 0; c < L; ++c) {
                if (r + 1 < H) {
                    int id1 = component_grid[r][c];
                    int id2 = component_grid[r + 1][c];
                    if (id1 != id2) {
                        int color1 = component_info[id1].first;
                        int color2 = component_info[id2].first;
                        if ((color1 == test_color || color1 == 0) && (color2 == test_color || color2 == 0)) {
                            dsu.unite(id1, id2);
                        }
                    }
                }
                if (c + 1 < L) {
                    int id1 = component_grid[r][c];
                    int id2 = component_grid[r][c + 1];
                    if (id1 != id2) {
                        int color1 = component_info[id1].first;
                        int color2 = component_info[id2].first;
                        if ((color1 == test_color || color1 == 0) && (color2 == test_color || color2 == 0)) {
                            dsu.unite(id1, id2);
                        }
                    }
                }
            }
        }

        vector<int> final_area_sizes;

        for(int i = 1; i < comp_id_counter; ++i) {
            int color = component_info[i].first;
            if(color != 0 && color != test_color) {
                final_area_sizes.push_back(component_info[i].second);
            }
        }
        
        map<int, int> merged_group_sizes;
        for(int i = 1; i < comp_id_counter; ++i) {
            int color = component_info[i].first;
            if(color == test_color || color == 0) {
                merged_group_sizes[dsu.find(i)] += component_info[i].second;
            }
        }
        for(auto const& [root, size] : merged_group_sizes) {
            if (size > 0) {
                 final_area_sizes.push_back(size);
            }
        }
        
        int current_min_area;
        if (final_area_sizes.empty()) {
            current_min_area = H * L;
        } else {
            current_min_area = final_area_sizes[0];
            for (size_t i = 1; i < final_area_sizes.size(); ++i) {
                current_min_area = min(current_min_area, final_area_sizes[i]);
            }
        }
        
        global_min_area = min(global_min_area, current_min_area);
    }
    
    cout << global_min_area << endl;

    return 0;
}
