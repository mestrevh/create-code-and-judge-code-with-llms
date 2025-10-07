/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    cin >> m;
    vector<int> B(m);
    for (int i = 0; i < m; ++i) {
        cin >> B[i];
    }

    unordered_set<int> setA(A.begin(), A.end());

    for (int j = 0; j < m; ++j) {
        if (setA.find(B[j]) == setA.end()) {
            cout << "0" << endl;
            return 0;
        }
    }
    cout << "1" << endl;
    return 0;
}
