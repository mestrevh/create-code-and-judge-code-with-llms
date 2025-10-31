/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int N, M, X;
    cin >> N >> M >> X;
    vector<vector<string>> matrix(N, vector<string>(M));
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> matrix[i][j];

    int rowIndex = X % N;
    for (int j = 0; j < M; j++) {
        if (j < M && j < matrix[rowIndex].size())
            cout << matrix[rowIndex][j];
        else
            cout << "Qualquer";
        
        if (j < M - 1)
            cout << " ";
    }
    cout << endl;

    return 0;
}
