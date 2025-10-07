/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int L, C;
    cin >> L >> C;
    vector<vector<int>> matriz(L, vector<int>(C, 0));
    int num = 1;

    for (int col = 0; col < C; col++) {
        for (int row = 0; row < L; row++) {
            matriz[row][col] = num++;
        }
    }

    for (int row = 0; row < L; row++) {
        for (int col = 0; col < C; col++) {
            cout << setw(3) << setfill('0') << matriz[row][col];
            if (col < C - 1) cout << " ";
        }
        cout << endl;
    }

    return 0;
}
