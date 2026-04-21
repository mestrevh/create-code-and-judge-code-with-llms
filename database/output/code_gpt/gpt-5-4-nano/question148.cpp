/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;

    map<char, int> holes = {
        {'A', 1}, {'D', 1}, {'O', 1}, {'P', 1}, {'R', 1},
        {'B', 2},
        {'C', 0}, {'E', 0}, {'F', 0}, {'K', 0}
    };

    while (T--) {
        string s;
        cin >> s;
        int ans = 0;
        for (char c : s) ans += holes[c];
        cout << ans << "\n";
    }
    return 0;
}