/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<vector<int>> A(n, vector<int>(n));
    vector<int> B;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> A[i][j];

    for (int i = 0; i < n; ++i)
        if (A[i][i] % x == 0)
            B.push_back(A[i][i]);

    if (B.empty())
        cout << "NMDX" << endl;
    else {
        for (size_t i = 0; i < B.size(); ++i) {
            cout << B[i];
            if (i < B.size() - 1) cout << " ";
        }
        cout << endl;
    }

    return 0;
}
