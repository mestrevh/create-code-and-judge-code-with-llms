/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    char direction;
    int rows, cols;
    cin >> direction >> rows >> cols;
    
    vector<vector<int>> matrix(rows, vector<int>(cols));
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
    
    if (direction == 'V') {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols / 2; j++) {
                swap(matrix[i][j + cols / 2], matrix[i][cols - 1 - j]);
            }
        }
    } else if (direction == 'H') {
        for (int i = 0; i < rows / 2; i++) {
            for (int j = 0; j < cols; j++) {
                swap(matrix[i + rows / 2][j], matrix[rows - 1 - i][j]);
            }
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (j > 0) cout << " ";
            cout << setw(2) << setfill('0') << matrix[i][j];
        }
        cout << endl;
    }

    return 0;
}
