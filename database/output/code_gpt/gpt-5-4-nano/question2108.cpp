/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int nA, nB;
    if (!(cin >> nA >> nB)) return 0;

    int k, m;
    cin >> k >> m;

    vector<int> A(nA), B(nB);
    for (int i = 0; i < nA; i++) cin >> A[i];
    for (int i = 0; i < nB; i++) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int maxA = A[k - 1];
    int minB = B[nB - m];

    cout << (maxA < minB ? "YES" : "NO");
    return 0;
}