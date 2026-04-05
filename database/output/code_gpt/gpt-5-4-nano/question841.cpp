/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double a, b, c;
    if (!(cin >> a >> b >> c)) return 0;

    double avg = (a + b + c) / 3.0;
    int cnt = 0;
    if (a > avg) cnt++;
    if (b > avg) cnt++;
    if (c > avg) cnt++;

    cout << cnt;
    return 0;
}