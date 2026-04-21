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

    long long cnt[5] = {0, 0, 0, 0, 0};
    for (char c : s) {
        c = (char)tolower((unsigned char)c);
        if (c == 'a') cnt[0]++;
        else if (c == 'e') cnt[1]++;
        else if (c == 'i') cnt[2]++;
        else if (c == 'o') cnt[3]++;
        else if (c == 'u') cnt[4]++;
    }

    cout << "A: " << cnt[0] << "\n";
    cout << "E: " << cnt[1] << "\n";
    cout << "I: " << cnt[2] << "\n";
    cout << "O: " << cnt[3] << "\n";
    cout << "U: " << cnt[4] << "\n";

    return 0;
}