/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;
    vector<int> A(N);
    int mn = INT_MAX, mx = INT_MIN;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        mn = min(mn, A[i]);
        mx = max(mx, A[i]);
    }

    int size = mx - mn + 1;
    vector<int> C(size, 0);
    for (int x : A) C[x - mn]++;

    for (int i = 0; i < size; i++) {
        cout << C[i] << (i + 1 < size ? " " : "");
    }
    cout << "\n";

    vector<int> B;
    B.reserve(N);
    for (int i = 0; i < size; i++) {
        for (int k = 0; k < C[i]; k++) B.push_back(i + mn);
    }

    for (int i = 0; i < (int)B.size(); i++) {
        cout << B[i] << (i + 1 < (int)B.size() ? " " : "");
    }
    return 0;
}