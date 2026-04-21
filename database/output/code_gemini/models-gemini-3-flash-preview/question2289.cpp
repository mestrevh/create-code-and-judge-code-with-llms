/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

/**
 * Problem: A Fuga III
 * Task: 
 * 1. Determine if at least one hostage is telling the truth.
 *    A hostage is telling the truth if their claim (that K people are 
 *    telling the truth) matches the actual number of truth-tellers.
 * 2. If truth exists, find a path from (0,0) to (N-1, M-1) in a grid.
 *    - Starting point: (0,0)
 *    - Exit point: (N-1, M-1)
 *    - Movement priority: Sul (South), Leste (East), Norte (North), Oeste (West)
 *    - Constraints: Must use recursion for pathfinding.
 */

int R, C;
int grid[1005][1005];
bool visited[1005][1005];
vector<string> path;

/**
 * Recursive function to find the path in the maze.
 * Priority: Sul (r+1), Leste (c+1), Norte (r-1), Oeste (c-1).
 */
bool solve(int r, int c) {
    if (r == R - 1 && c == C - 1) return true;
    visited[r][c] = true;

    // Try Sul (South)
    if (r + 1 < R && grid[r + 1][c] == 1 && !visited[r + 1][c]) {
        path.push_back("Sul");
        if (solve(r + 1, c)) return true;
        path.pop_back();
    }
    // Try Leste (East)
    if (c + 1 < C && grid[r][c + 1] == 1 && !visited[r][c + 1]) {
        path.push_back("Leste");
        if (solve(r, c + 1)) return true;
        path.pop_back();
    }
    // Try Norte (North)
    if (r - 1 >= 0 && grid[r - 1][c] == 1 && !visited[r - 1][c]) {
        path.push_back("Norte");
        if (solve(r - 1, c)) return true;
        path.pop_back();
    }
    // Try Oeste (West)
    if (c - 1 >= 0 && grid[r][c - 1] == 1 && !visited[r][c - 1]) {
        path.push_back("Oeste");
        if (solve(r, c - 1)) return true;
        path.pop_back();
    }

    return false;
}

int main() {
    // Optimization for fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int numHostages;
    if (!(cin >> numHostages)) return 0;

    // Truth-teller detection logic: 
    // Hostage who says "k" is telling the truth iff exactly k people say "k".
    map<int, int> hostageCounts;
    for (int i = 0; i < numHostages; ++i) {
        int response;
        cin >> response;
        hostageCounts[response]++;
    }

    bool truthExists = false;
    for (auto const& [val, count] : hostageCounts) {
        if (val > 0 && val == count) {
            truthExists = true;
            break;
        }
    }

    // Grid dimension and structure must be read regardless of truth status
    if (!(cin >> R >> C)) return 0;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> grid[i][j];
            visited[i][j] = false;
        }
    }

    if (!truthExists) {
        cout << "Ja nao se pode confiar nos refens como antigamente..." << endl;
    } else {
        cout << "Vamos nessa, temos que sair rapido..." << endl;
        
        // Ensure starting point is valid before calling recursion
        if (R > 0 && C > 0 && grid[0][0] == 1 && solve(0, 0)) {
            for (int i = 0; i < (int)path.size(); ++i) {
                cout << path[i] << (i == (int)path.size() - 1 ? "" : ", ");
            }
            cout << endl;
        } else {
            cout << "Continuem cavando!" << endl;
        }
    }

    return 0;
}