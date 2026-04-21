/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

/**
 * Competitive Programming Solution - Maze Collision
 * Persona: Grandmaster in Competitive Programming (ICPC style)
 * Complexity: O(N*M + C)
 */

int main() {
    // Fast I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    // Grid storage: 0 = wall, 1 = path
    // Using vector for dynamic memory allocation based on input size
    vector<vector<int>> grid(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> grid[i][j];
        }
    }

    // Number of movement commands
    int C;
    if (!(cin >> C)) return 0;

    // Sequence of C movement commands (D, E, C, B)
    // Commands are stored first because start coordinates appear later in input stream
    vector<char> cmds(C);
    for (int i = 0; i < C; ++i) {
        cin >> cmds[i];
    }

    // Initial position: row (X) and column (Y)
    int curX, curY;
    if (!(cin >> curX >> curY)) return 0;

    // Execute each movement command
    for (int i = 0; i < C; ++i) {
        char cmd = cmds[i];
        int nxtX = curX;
        int nxtY = curY;

        // Determine target position based on direction
        if (cmd == 'C') { // Up (Cima)
            nxtX--;
        } else if (cmd == 'B') { // Down (Baixo)
            nxtX++;
        } else if (cmd == 'E') { // Left (Esquerda)
            nxtY--;
        } else if (cmd == 'D') { // Right (Direita)
            nxtY++;
        }

        // Collision Check: 
        // 1. Must stay within boundaries (0 to N-1 for rows, 0 to M-1 for columns)
        // 2. Must move to a path (grid value == 1)
        if (nxtX >= 0 && nxtX < N && nxtY >= 0 && nxtY < M) {
            if (grid[nxtX][nxtY] == 1) {
                curX = nxtX;
                curY = nxtY;
            }
        }
        // If it hits a wall (0) or boundary, curX and curY remain unchanged.
    }

    // Final output in the format (row,column)
    cout << "(" << curX << "," << curY << ")" << endl;

    return 0;
}