/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!getline(cin, s)) return 0;

    for (char &c : s) c = (char)tolower((unsigned char)c);

    string target = "vou passar em p1";
    vector<int> need(256, 0);
    for (char c : target) need[(unsigned char)c]++;

    vector<int> have(256, 0);
    for (char c : s) have[(unsigned char)c]++;

    int ans = INT_MAX;
    for (int i = 0; i < 256; i++) {
        if (need[i] > 0) ans = min(ans, have[i] / need[i]);
    }

    if (ans == INT_MAX) ans = 0;
    cout << ans << "\n";
    return 0;
}