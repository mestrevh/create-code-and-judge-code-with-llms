/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int T;
    cin >> T;
    cin.ignore();
    
    while (T--) {
        string line;
        getline(cin, line);
        int C = line.size();
        int N = sqrt(C);
        
        if (N * N != C) {
            cout << "INVALIDO" << endl;
            continue;
        }
        
        vector<vector<char>> matrix(N, vector<char>(N));
        
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                matrix[i][j] = line[i * N + j];
            }
        }
        
        string decoded;
        for (int j = 0; j < N; ++j) {
            for (int i = 0; i < N; ++i) {
                decoded += matrix[i][j];
            }
        }
        
        cout << decoded << endl;
    }
    
    return 0;
}
