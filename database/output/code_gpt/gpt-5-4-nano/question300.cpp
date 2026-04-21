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
    int dir = 1;

    const long long MAX_H = 200;
    const long long MAX_D = 2000;

    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;

        if (c == 'D') {
            if (y == 0) continue;
            if (y - 10 >= 0) y -= 10;
        } else if (c == 'S') {
            if (y + 10 <= MAX_H) y += 10;
        } else if (c == 'V') {
            if (y == 0) continue;
            dir *= -1;
        } else if (c == 'F') {
            if (y == 0) continue;
            if (x + dir * 10 >= -MAX_D && x + dir * 10 <= MAX_D) x += dir * 10;
        }
    }

    cout << y << " " << llabs(x) << "\n";
    return 0;
}