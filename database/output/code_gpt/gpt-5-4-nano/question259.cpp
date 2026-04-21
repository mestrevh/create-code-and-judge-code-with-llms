/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int N = 60;
    const int L = 720;

    vector<int> possible(181, 0);

    for (int t = 0; t < L; t++) {
        int h = (5 * t / 60) % 60;
        int m = t % 60;

        int diff = abs(m - h) % 60;
        int ang = min(diff, 60 - diff) * 3;

        if (0 <= ang && ang <= 180) possible[ang] = 1;

        if (t % 60 == 59) {
            int hh = (5 * (t + 1) / 60) % 60;
            int mm = (t + 1) % 60;
            if (t + 1 < L) {
                int d = abs(mm - hh) % 60;
                int a = min(d, 60 - d) * 3;
                possible[a] = 1;
            }
        }
    }

    int A;
    while (cin >> A) {
        if (A == -1) break;
        if (A >= 0 && A <= 180 && possible[A]) cout << 'Y' << "\n";
        else cout << 'N' << "\n";
    }
    return 0;
}