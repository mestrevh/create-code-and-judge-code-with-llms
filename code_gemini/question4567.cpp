/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    if (m != a) {
        cout << "Nao eh possivel multiplicar!" << endl;
        return 0;
    }

    vector<vector<int>> mat1(n, vector<int>(m));
    vector<vector<int>> mat2(a, vector<int>(b));
    vector<vector<int>> result(n, vector<int>(b));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat1[i][j];
        }
    }

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cin >> mat2[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < b; j++) {
            for (int k = 0; k < m; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < b; j++) {
            cout << result[i][j] << (j == b - 1 ? "" : " ");
        }
        cout << endl;
    }

    return 0;
}
