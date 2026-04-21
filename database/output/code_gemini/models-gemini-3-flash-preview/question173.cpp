/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int countSwaps(vector<int>& p) {
    int n = p.size();
    int swaps = 0;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int curr = i;
            int cycleSize = 0;
            while (!visited[curr]) {
                visited[curr] = true;
                curr = p[curr];
                cycleSize++;
            }
            if (cycleSize > 1) {
                swaps += (cycleSize - 1);
            }
        }
    }
    return swaps;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int L, C;
    if (!(cin >> L >> C)) return 0;

    vector<vector<int>> grid(L, vector<int>(C));
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
        }
    }

    vector<int> rowPerm(L);
    for (int i = 0; i < L; i++) {
        rowPerm[i] = (grid[i][0] - 1) / C;
    }

    vector<int> colPerm(C);
    for (int j = 0; j < C; j++) {
        colPerm[j] = (grid[0][j] - 1) % C;
    }

    int totalSwaps = countSwaps(rowPerm) + countSwaps(colPerm);
    cout << totalSwaps << endl;

    return 0;
}

