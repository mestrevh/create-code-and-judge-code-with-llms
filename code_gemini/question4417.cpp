/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, b;
    cin >> n >> b;

    vector<vector<char>> board(n, vector<char>(n, '-'));

    int bit_pos = 0;
    while (b > 0) {
        if (b & 1) {
            board[0][bit_pos] = 'x';
        }
        b >>= 1;
        bit_pos++;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << board[i][j];
        }
        cout << endl;
    }

    return 0;
}
