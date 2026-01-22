/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, field_count = 0;
    while (cin >> n >> m, n || m) {
        field_count++;
        vector<string> field(n);
        vector<vector<int>> count(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
            cin >> field[i];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (field[i][j] == '*') {
                    for (int di = -1; di <= 1; di++)
                        for (int dj = -1; dj <= 1; dj++)
                            if (di || dj) {
                                int ni = i + di, nj = j + dj;
                                if (ni >= 0 && ni < n && nj >= 0 && nj < m)
                                    count[ni][nj]++;
                            }
                }

        cout << "Field #" << field_count << ":\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (field[i][j] == '*')
                    cout << '*';
                else
                    cout << count[i][j];
            }
            cout << '\n';
        }
        cout << '\n';
    }
    return 0;
}
