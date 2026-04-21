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

    int H = (N - 1) / 2;

    for (int r = 0; r < 2 * H + 1; r++) {
        int size = N - 2 * r;
        int stars = size;
        int dashesLeft = (N - stars) / 2;
        cout << string(dashesLeft, '-') << string(stars, '*') << string(dashesLeft, '-');
        cout << "\n";
    }

    for (int r = 0; r < H; r++) {
        int size = 2 * r + 1;
        int dashesLeft = (N - size) / 2;
        cout << string(dashesLeft, '-') << string(size, '*') << string(dashesLeft, '-');
        cout << "\n";
    }

    cout << "\n";
    return 0;
}