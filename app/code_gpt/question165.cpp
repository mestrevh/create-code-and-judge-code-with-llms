/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

bool isMagicSquare(const vector<vector<int>>& square, int N, int &magic_sum) {
    magic_sum = 0;
    for (int j = 0; j < N; ++j) magic_sum += square[0][j];
    
    for (int i = 1; i < N; ++i) {
        int row_sum = 0;
        for (int j = 0; j < N; ++j) row_sum += square[i][j];
        if (row_sum != magic_sum) return false;
    }
    
    for (int j = 0; j < N; ++j) {
        int col_sum = 0;
        for (int i = 0; i < N; ++i) col_sum += square[i][j];
        if (col_sum != magic_sum) return false;
    }
    
    int diag1_sum = 0, diag2_sum = 0;
    for (int i = 0; i < N; ++i) {
        diag1_sum += square[i][i];
        diag2_sum += square[i][N - 1 - i];
    }
    
    return diag1_sum == magic_sum && diag2_sum == magic_sum;
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> square(N, vector<int>(N));
    
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> square[i][j];
    
    int magic_sum;
    if (isMagicSquare(square, N, magic_sum)) 
        cout << magic_sum << endl;
    else 
        cout << -1 << endl;
    
    return 0;
}
