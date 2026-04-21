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

    long long x = 0, y = 0;
    int side = 0; // 0: y<x (below), 1: y>x (above), 2: on line
    if (y < x) side = 0;
    else if (y > x) side = 1;
    else side = 2;

    long long ans = 0;

    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        long long nx = x, ny = y;
        if (c == 'D') nx++;
        else ny++;

        int ns;
        if (ny < nx) ns = 0;
        else if (ny > nx) ns = 1;
        else ns = 2;

        if (side != 2 && ns != side) {
            if (ns == 2) {
                x = nx; y = ny; side = ns;
            } else {
                ans++;
                x = nx; y = ny; side = ns;
            }
        } else {
            x = nx; y = ny; side = ns;
            if (side == 2) {
                int tempSide = 0;
            }
            if (ns == 2 && side != 2) {
                ans++;
            }
        }

        if (side == 2) {
            long long diff = ny - nx;
            if (diff == 0) side = 2;
        }
    }

    cout << ans << "\n";
    return 0;
}