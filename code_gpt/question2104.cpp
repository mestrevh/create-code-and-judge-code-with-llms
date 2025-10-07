/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

bool isMagicSquare(const vector<vector<int>>& matrix, int n) {
    int sum = 0;
    for (int j = 0; j < n; ++j) {
        sum += matrix[0][j];
    }

    // Check rows
    for (int i = 0; i < n; ++i) {
        int rowSum = 0;
        for (int j = 0; j < n; ++j) {
            rowSum += matrix[i][j];
        }
        if (rowSum != sum) return false;
    }

    // Check columns
    for (int j = 0; j < n; ++j) {
        int colSum = 0;
        for (int i = 0; i < n; ++i) {
            colSum += matrix[i][j];
        }
        if (colSum != sum) return false;
    }

    // Check main diagonal
    int diagSum1 = 0, diagSum2 = 0;
    for (int i = 0; i < n; ++i) {
        diagSum1 += matrix[i][i];
        diagSum2 += matrix[i][n - i - 1];
    }

    return diagSum1 == sum && diagSum2 == sum;
}

int main() {
    int L;
    cin >> L;
    vector<vector<int>> matrix(L, vector<int>(L));
    
    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < L; ++j) {
            cin >> matrix[i][j];
        }
    }

    if (isMagicSquare(matrix, L)) {
        cout << "A matriz e magica" << endl;
    } else {
        cout << "A matriz nao e magica" << endl;
    }

    return 0;
}
