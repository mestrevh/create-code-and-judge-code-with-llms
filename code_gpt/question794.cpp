/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

pair<int, int> move[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool backtrack(const vector<string>& grid, const string& word, int x, int y, vector<pair<int, int>>& positions, vector<vector<bool>>& visited, int index) {
    if (index == word.size()) return true;
    if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || visited[x][y] || grid[x][y] != word[index]) return false;
    
    visited[x][y] = true;
    positions.push_back({x + 1, y + 1});
    
    for (auto& m : move) {
        if (backtrack(grid, word, x + m.first, y + m.second, positions, visited, index + 1)) return true;
    }

    visited[x][y] = false;
    positions.pop_back();
    return false;
}

vector<pair<int, int>> findWord(const vector<string>& grid, const string& word) {
    vector<pair<int, int>> positions;
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    
    for (int i = 0; i < grid.size(); i++)
        for (int j = 0; j < grid[0].size(); j++)
            if (grid[i][j] == word[0]) {
                if (backtrack(grid, word, i, j, positions, visited, 0)) return positions;
            }
    
    return {};  // return empty if not found
}

int main() {
    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        int N, A, L;
        iss >> N >> A >> L;
        if (N == 0 && A == 0 && L == 0) break;

        vector<string> words(N);
        for (int i = 0; i < N; i++) getline(cin, words[i]);

        vector<string> grid(A);
        for (int i = 0; i < A; i++) getline(cin, grid[i]);

        for (int i = 0; i < N; i++) {
            vector<pair<int, int>> pos = findWord(grid, words[i]);
            for (size_t j = 0; j < pos.size(); j++) {
                cout << pos[j].first * 10 + pos[j].second; // Encode the positions as specified
                if (j < pos.size() - 1) cout << ' ';
            }
            cout << endl;
        }
        cout << endl; // Separator for test cases
    }
    return 0;
}
