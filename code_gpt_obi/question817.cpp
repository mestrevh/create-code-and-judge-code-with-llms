/*
Código criado pelo modelo gpt-4.1
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/de <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; ++i) cin >> H[i];

    vector<int> lmax(N), rmax(N);
    lmax[0] = H[0];
    for (int i = 1; i < N; ++i) lmax[i] = max(lmax[i-1], H[i]);
    rmax[N-1] = H[N-1];
    for (int i = N - 2; i >= 0; --i) rmax[i] = max(rmax[i+1], H[i]);

    int res = 0;
    for (int i = 0; i < N; ++i) {
        int w = min(lmax[i], rmax[i]) - H[i];
        if (w >= 1) ++res;
    }
    cout << res << endl;
    return 0