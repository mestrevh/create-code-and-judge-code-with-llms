/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, caseNum = 1;
    while (cin >> n >> m) {
        vector<int> A(n + 1), B(m + 1), C(n + m + 1, 0);
        for (int i = 0; i <= n; ++i) cin >> A[i];
        for (int i = 0; i <= m; ++i) cin >> B[i];
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                C[i + j] += A[i] * B[j];
            }
        }
        cout << "Caso #" << caseNum++ << ":";
        for (int i = 0; i <= n + m; ++i) cout << " " << C[i];
        cout << endl;
    }
    return 0;
}
