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

    int N;
    if (!(cin >> N)) return 0;

    vector<string> grid(N);
    for (int i = 0; i < N; i++) {
        cin >> grid[i];
    }

    char m;
    while (cin >> m) {
        if (m == 'L') {
            for (int i = 0; i < N; i++) {
                string items = "";
                for (int j = 0; j < N; j++) {
                    if (grid[i][j] != 'x') items += grid[i][j];
                }
                while ((int)items.size() < N) {
                    items += 'x';
                }
                grid[i] = items;
            }
        } else if (m == 'R') {
            for (int i = 0; i < N; i++) {
                string items = "";
                for (int j = 0; j < N; j++) {
                    if (grid[i][j] != 'x') items += grid[i][j];
                }
                string res = "";
                int blanks = N - (int)items.size();
                for (int j = 0; j < blanks; j++) {
                    res += 'x';
                }
                res += items;
                grid[i] = res;
            }
        } else if (m == 'U') {
            for (int j = 0; j < N; j++) {
                string items = "";
                for (int i = 0; i < N; i++) {
                    if (grid[i][j] != 'x') items += grid[i][j];
                }
                int idx = 0;
                for (int i = 0; i < (int)items.size(); i++) {
                    grid[idx++][j] = items[i];
                }
                while (idx < N) {
                    grid[idx++][j] = 'x';
                }
            }
        } else if (m == 'D') {
            for (int j = 0; j < N; j++) {
                string items = "";
                for (int i = 0; i < N; i++) {
                    if (grid[i][j] != 'x') items += grid[i][j];
                }
                int blanks = N - (int)items.size();
                int idx = 0;
                for (int i = 0; i < blanks; i++) {
                    grid[idx++][j] = 'x';
                }
                for (int i = 0; i < (int)items.size(); i++) {
                    grid[idx++][j] = items[i];
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << grid[i] << "\n";
    }

    return 0;
}