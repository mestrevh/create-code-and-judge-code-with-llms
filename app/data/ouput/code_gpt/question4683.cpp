/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

void printMatrix(const vector<vector<int>>& mat) {
    for (const auto& row : mat) {
        for (int el : row)
            cout << el << " ";
        cout << endl;
    }
    cout << endl;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> matrix[i][j];

    int count = 0;
    for (int j = 1; j < m - 1; ++j) {
        bool inSymbol = false;
        int start = -1;

        for (int i = 0; i < n; ++i) {
            if (matrix[i][j] == 1) {
                if (!inSymbol) {
                    inSymbol = true;
                    start = j;
                }
            } else {
                if (inSymbol) {
                    inSymbol = false;
                    int end = j - 1;

                    vector<vector<int>> subMatrix(n, vector<int>(end - start + 2, 0));
                    for (int k = 0; k < n; ++k) {
                        for (int l = start; l <= end; ++l) {
                            subMatrix[k][l - start + 1] = matrix[k][l];
                        }
                    }
                    if ((end - start + 1) % 2 == 1) {
                        ++end; // para garantir que o primeiro terá uma coluna extra
                    }
                    int extraCols = (end - start + 1) / 2;
                    for (int k = 0; k < n; ++k) {
                        for (int l = 0; l < extraCols; ++l) {
                            subMatrix[k][0] = matrix[k][start - 1];
                        }
                        for (int l = 0; l < extraCols; ++l) {
                            subMatrix[k][subMatrix[0].size() - 1] = matrix[k][end + 1];
                        }
                    }
                    printMatrix(subMatrix);
                    ++count;
                }
            }
        }
        if (inSymbol) {
            inSymbol = false;
            int end = m - 2;

            vector<vector<int>> subMatrix(n, vector<int>(end - start + 2, 0));
            for (int k = 0; k < n; ++k) {
                for (int l = start; l <= end; ++l) {
                    subMatrix[k][l - start + 1] = matrix[k][l];
                }
            }
            int extraCols = (end - start + 1) / 2 + 1; // para garantir que a primeira terá uma coluna extra
            for (int k = 0; k < n; ++k) {
                for (int l = 0; l < extraCols; ++l) {
                    subMatrix[k][0] = matrix[k][start - 1];
                }
                subMatrix[k][subMatrix[0].size() - 1] = matrix[k][end + 1];
            }
            printMatrix(subMatrix);
            ++count;
        }
    }
    
    cout << "Foram encontrados " << count << " simbolos!" << endl;

    return 0;
}
