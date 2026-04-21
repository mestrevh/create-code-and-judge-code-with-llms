/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

long long solveRec(const vector<long long>& a, int l, int r) {
    int len = r - l;
    if (len == 1) return a[l] > 10 ? a[l] : 0;
    int mid = l + (len / 2);
    return solveRec(a, l, mid) + solveRec(a, mid, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;
    vector<long long> x(N);
    for (int i = 0; i < N; i++) cin >> x[i];

    cout << solveRec(x, 0, N) << "\n";
    return 0;
}