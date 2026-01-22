/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

bool find_path(int r, int c, int m, int n,
               std::vector<std::vector<int>>& map,
               std::vector<std::vector<bool>>& visited,
               std::vector<std::string>& path) {
    
    if (r < 0 || r >= m || c < 0 || c >= n || map[r][c] == 0 || visited[r][c]) {
        return false;
    }

    visited[r][c] = true;

    if ((r == m - 1 || c == n - 1) && (r != 0 || c != 0)) {
        return true; 
    }
    
    path.push_back("Sul");
    if (find_path(r + 1, c, m, n, map, visited, path)) {
        return true;
    }
    path.pop_back();

    path.push_back("Leste");
    if (find_path(r, c + 1, m, n, map, visited, path)) {
        return true;
    }
    path.pop_back();

    path.push_back("Norte");
    if (find_path(r - 1, c, m, n, map, visited, path)) {
        return true;
    }
    path.pop_back();

    path.push_back("Oeste");
    if (find_path(r, c - 1, m, n, map, visited, path)) {
        return true;
    }
    path.pop_back();
    
    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int m, n;
    std::cin >> m >> n;

    if (m <= 0 || n <= 0) {
        std::cout << "Welcome to the Upside Down." << std::endl;
        return 0;
    }

    std::vector<std::vector<int>> map(m, std::vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> map[i][j];
        }
    }

    if (map[0][0] == 0) {
        std::cout << "Welcome to the Upside Down." << std::endl;
        return 0;
    }

    std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));
    std::vector<std::string> path;

    if (find_path(0, 0, m, n, map, visited, path)) {
        for (size_t i = 0; i < path.size(); ++i) {
            std::cout << path[i] << (i == path.size() - 1 ? "" : ", ");
        }
        std::cout << std::endl;
    } else {
        std::cout << "Welcome to the Upside Down." << std::endl;
    }

    return 0;
}
