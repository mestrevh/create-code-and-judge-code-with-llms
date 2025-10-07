/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

bool isMagicSquare(const vector<vector<int>>& matrix, int n) {
    int magicSum = 0;
    
    for (int j = 0; j < n; j++) 
        magicSum += matrix[0][j];
    
    for (int i = 0; i < n; i++) {
        int rowSum = 0;
        for (int j = 0; j < n; j++) 
            rowSum += matrix[i][j];
        if (rowSum != magicSum) return false;
    }
    
    for (int j = 0; j < n; j++) {
        int colSum = 0;
        for (int i = 0; i < n; i++) 
            colSum += matrix[i][j];
        if (colSum != magicSum) return false;
    }
    
    int diag1Sum = 0, diag2Sum = 0;
    for (int i = 0; i < n; i++) {
        diag1Sum += matrix[i][i];
        diag2Sum += matrix[i][n - 1 - i];
    }
    
    return diag1Sum == magicSum && diag2Sum == magicSum;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            cin >> matrix[i][j];
    
    if (n != m || !isMagicSquare(matrix, n)) 
        cout << "A matriz recebida nao e magica." << endl;
    else 
        cout << "A matriz recebida e magica." << endl;

    return 0;
}
