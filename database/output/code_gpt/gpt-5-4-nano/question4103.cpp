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

    int code, pos = 0;
    int ans = -1;
    int X;
    vector<int> values;
    while (cin >> code) {
        if (code == -1) break;
        values.push_back(code);
    }
    cin >> X;

    if (X >= 1 && X <= (int)values.size()) ans = values[X - 1];
    cout << ans << "\n";
    return 0;
}