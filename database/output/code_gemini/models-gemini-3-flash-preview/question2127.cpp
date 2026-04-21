/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int grid[10][10];
bool visited[10][10];

bool hasPath(int r, int c) {
    if (r == 9 && c == 9) {
        return true;
    }
    
    visited[r][c] = true;
    
    // Priority based on D > DS > L > U: Down, Right, Left, Up
    int dr[] = {1, 0, 0, -1};
    int dc[] = {0, 1, -1, 0};
    
    for (int i = 0; i < 4; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        
        if (nr >= 0 && nr < 10 && nc >= 0 && nc < 10 && 
            grid[nr][nc] == 1 && !visited[nr][nc]) {
            if (hasPath(nr, nc)) {
                return true;
            }
        }
    }
    
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (!(cin >> grid[i][j])) break;
            visited[i][j] = false;
        }
    }
    
    if (grid[0][0] == 1 && hasPath(0, 0)) {
        cout << "RUN!" << endl;
    } else {
        cout << "Welcome to the Upside Down." << endl;
    }
    
    return 0;
}