/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

const int MAXN = 10;
const int di[4] = {1, 0, -1, 0};
const int dj[4] = {0, 1, 0, -1};
const string directions[4] = {"Sul", "Leste", "Norte", "Oeste"};

bool isSafe(int x, int y, vector<vector<int>>& maze, vector<vector<bool>>& visited) {
    return (x >= 0 && x < maze.size() && y >= 0 && y < maze[0].size() && maze[x][y] == 1 && !visited[x][y]);
}

bool findPath(int x, int y, vector<vector<int>>& maze, vector<vector<bool>>& visited, string& path) {
    if (x == maze.size() - 1 && y == maze[0].size() - 1) {
        return true;
    }

    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int newX = x + di[i], newY = y + dj[i];
        if (isSafe(newX, newY, maze, visited)) {
            path += (path.empty() ? "" : ", ") + directions[i];
            if (findPath(newX, newY, maze, visited, path)) {
                return true;
            }
            path.erase(path.size() - directions[i].size() - (path.empty() ? 0 : 2), directions[i].size() + (path.empty() ? 0 : 2));
        }
    }

    visited[x][y] = false;
    return false;
}

int main() {
    int N;
    cin >> N;
    vector<int> truths(N);
    
    for (int i = 0; i < N; i++) {
        cin >> truths[i];
    }

    int count = 0;
    for (int x : truths) {
        if (x > 0) count++;
    }

    if (count > 0) {
        cout << "Vamo nessa, temos que sair rapido..." << endl;

        int mazeN, mazeM;
        cin >> mazeN >> mazeM;
        vector<vector<int>> maze(mazeN, vector<int>(mazeM));
        
        for (int i = 0; i < mazeN; i++) {
            for (int j = 0; j < mazeM; j++) {
                cin >> maze[i][j];
            }
        }

        vector<vector<bool>> visited(mazeN, vector<bool>(mazeM, false));
        string path;

        if (findPath(0, 0, maze, visited, path)) {
            cout << path << endl;
        } else {
            cout << "Continuem cavando!" << endl;
        }
    } else {
        cout << "Ja nao se pode confiar nos refens como antigamente..." << endl;
    }

    return 0;
}
