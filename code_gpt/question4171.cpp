/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int k;
    cin >> k;
    vector<vector<int>> pascal(k);

    for (int i = 0; i < k; ++i) {
        pascal[i].resize(i + 1);
        pascal[i][0] = 1;
        pascal[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
        }
    }

    for (const auto &row : pascal) {
        for (const auto &num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
