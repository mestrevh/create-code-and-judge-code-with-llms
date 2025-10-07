/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> pascal(N + 1);

    for (int i = 0; i <= N; ++i) {
        pascal[i].resize(i + 1);
        pascal[i][0] = 1;
        pascal[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
        }
    }

    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= i; ++j) {
            cout << pascal[i][j] << (j < i ? " " : "");
        }
        cout << endl;
    }

    return 0;
}
