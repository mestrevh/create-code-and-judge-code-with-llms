/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int L, C;
    cin >> L >> C;
    vector<vector<int>> grid(L, vector<int>(C));
    
    for (int i = 0; i < L; ++i)
        for (int j = 0; j < C; ++j)
            cin >> grid[i][j];
    
    int D;
    cin >> D;
    int destroyed = 0;

    if (L % 2 == 0) {
        for (int i = 0; i < L; ++i) {
            for (int j = 0; j < C; ++j) {
                if (D > 0 && grid[i][j] == 1) {
                    grid[i][j] = 0;
                    D--;
                    destroyed++;
                }
            }
        }
    } else {
        for (int j = 0; j < C; ++j) {
            for (int i = 0; i < L; ++i) {
                if (D > 0 && grid[i][j] == 1) {
                    grid[i][j] = 0;
                    D--;
                    destroyed++;
                }
            }
        }
    }

    for (const auto& row : grid) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
    cout << D << " " << (L * C - destroyed) << endl;
    
    return 0;
}
