/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

bool isMagicSquare(const vector<vector<int>>& square, int N, int &magicSum) {
    magicSum = 0;
    for (int j = 0; j < N; j++) magicSum += square[0][j];

    for (int i = 0; i < N; i++) {
        int rowSum = 0, colSum = 0;
        for (int j = 0; j < N; j++) {
            rowSum += square[i][j];
            colSum += square[j][i];
        }
        if (rowSum != magicSum || colSum != magicSum) return false;
    }
    
    int diagSum1 = 0, diagSum2 = 0;
    for (int i = 0; i < N; i++) {
        diagSum1 += square[i][i];
        diagSum2 += square[i][N - 1 - i];
    }
    return diagSum1 == magicSum && diagSum2 == magicSum;
}

int main() {
    int N;
    cout << "Digite a dimensao da matriz quadrada N x N:\n";
    cin >> N;
    
    vector<vector<int>> square(N, vector<int>(N));
    cout << "Digite os elementos da matriz:\n";
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> square[i][j];

    int magicSum;
    if (isMagicSquare(square, N, magicSum)) {
        cout << "Os elementos FORMAM um quadrado magico.\n";
        cout << "A soma do quadrado magico e " << magicSum << ".\n";
    } else {
        cout << "Os elementos NAO FORMAM um quadrado magico.\n";
    }
    return 0;
}
