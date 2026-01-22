/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int H, W, P, EX, EY, DX, DY;
    cin >> H >> W >> P;
    cin >> EX >> EY >> DX >> DY;

    vector<vector<char>> plano(H, vector<char>(W, '.'));

    for (int i = DY; i <= EY; ++i) {
        for (int j = EX; j <= DX; ++j) {
            if (P == 1 || i == DY || i == EY || j == EX || j == DX)
                plano[i][j] = '*';
        }
    }

    for (const auto& linha : plano) {
        for (char c : linha)
            cout << c;
        cout << endl;
    }

    return 0;
}
