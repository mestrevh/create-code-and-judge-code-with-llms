/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H1, M1, H2, M2;
    while (cin >> H1 >> M1 >> H2 >> M2) {
        if (H1 == 0 && M1 == 0 && H2 == 0 && M2 == 0) break;
        int t1 = H1 * 60 + M1;
        int t2 = H2 * 60 + M2;
        int diff = (t2 - t1 + 24 * 60) % (24 * 60);
        if (diff == 0) diff = 24 * 60;
        cout << diff << "\n";
    }
    return 0;
}