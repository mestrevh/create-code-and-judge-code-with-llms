/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int health;
    if (!(cin >> health)) return 0;

    vector<vector<string>> grid(5, vector<string>(5));
    int r = -1, c = -1;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == "@") {
                r = i;
                c = j;
            }
        }
    }

    int d;
    if (!(cin >> d)) d = 0;
    
    bool won = false;
    bool dead = false;

    for (int i = 0; i < d; ++i) {
        char move;
        if (!(cin >> move)) break;
        
        if (won || dead) continue;

        int nr = r, nc = c;
        if (move == 'C') {
            nr--;
        } else if (move == 'E') {
            nc--;
        } else if (move == 'D') {
            nc++;
        }

        if (nr < 0 || nr >= 5 || nc < 0 || nc >= 5 || grid[nr][nc] == "#") {
            cout << "Uma magic wall aqui? druid desgraçado" << endl;
        } else if (grid[nr][nc] == "$") {
            grid[r][c] = "*";
            r = nr;
            c = nc;
            grid[r][c] = "@";
            won = true;
        } else if (grid[nr][nc] == "*" || grid[nr][nc] == "@") {
            grid[r][c] = "*";
            r = nr;
            c = nc;
            grid[r][c] = "@";
        } else {
            // Cell contains a dragon strength integer
            int strength = stoi(grid[nr][nc]);
            if (health > strength) {
                health -= strength;
                cout << "Minha Royal Spear deita qualquer Dragon" << endl;
                grid[r][c] = "*";
                r = nr;
                c = nc;
                grid[r][c] = "@";
            } else {
                cout << "Minhas HPs acabaram, esse Frost Dragon me deitou" << endl;
                dead = true;
            }
        }
    }

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << grid[i][j] << (j == 4 ? "" : " ");
        }
        cout << endl;
    }

    if (won) {
        cout << "Finalmente acabei a quest" << endl;
    } else {
        cout << "Quem foi o newba que escreveu essas coordenadas" << endl;
    }

    return 0;
}