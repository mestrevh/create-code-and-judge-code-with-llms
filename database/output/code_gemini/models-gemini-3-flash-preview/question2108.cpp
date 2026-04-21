/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int nA, nB;
    if (!(cin >> nA >> nB)) return 0;

    int k, m;
    if (!(cin >> k >> m)) return 0;

    vector<int> A(nA);
    for (int i = 0; i < nA; ++i) {
        cin >> A[i];
    }

    vector<int> B(nB);
    for (int i = 0; i < nB; ++i) {
        cin >> B[i];
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    if (A[k - 1] < B[nB - m]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}