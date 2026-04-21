/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    if (!(cin >> m >> n)) return 0;

    vector<vector<long long>> matrix(m, vector<long long>(m));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }

    vector<vector<bool>> visited(m, vector<bool>(m, false));
    bool lost = false;

    for (int i = 0; i < n; ++i) {
        int x, y;
        if (!(cin >> x >> y)) break;

        if (x < 0 || x >= m || y < 0 || y >= m) continue;

        if (visited[x][y]) {
            cout << "Essa casa ja foi selecionada." << endl;
            continue;
        }

        long long sum_r = 0;
        for (int j = y; j < m; ++j) {
            if (matrix[x][j] != -1) {
                sum_r += matrix[x][j];
            }
        }

        long long sum_b = 0;
        for (int k = x; k < m; ++k) {
            if (matrix[k][y] != -1) {
                sum_b += matrix[k][y];
            }
        }

        long long sum_d = 0;
        for (int k = 0; x + k < m && y + k < m; ++k) {
            if (matrix[x + k][y + k] != -1) {
                sum_d += matrix[x + k][y + k];
            }
        }

        if (sum_r == sum_b && sum_b == sum_d) {
            cout << "Bomba encontrada." << endl;
            cout << "Voce perdeu." << endl;
            lost = true;
            break;
        } else {
            matrix[x][y] = -1;
            visited[x][y] = true;
            cout << "Boa jogada, a casa (" << x << "," << y << ") nao tinha bomba." << endl;
        }
    }

    if (!lost) {
        cout << "Voce e uma pessoa de sorte." << endl;
    }

    return 0;
}