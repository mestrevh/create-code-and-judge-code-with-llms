/*
Código criado pelo modelo gpt-4.1
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> h(N), lmax(N), rmax(N);
    for (int i = 0; i < N; ++i) cin >> h[i];

    lmax[0] = h[0];
    for (int i = 1; i < N; ++i)
        lmax[i] = max(lmax[i-1], h[i]);

    rmax[N-1] = h[N-1];
    for (int i = N-2; i >= 0; --i)
        rmax[i] = max(rmax[i+1], h[i]);

    int covered = 0;
    for (int i = 0; i < N; ++i) {
        int water = min(lmax[i], rmax[i]) - h[i];
        if (water >= 1) ++covered;
    }
    cout << covered << endl;
    return 0;
}
