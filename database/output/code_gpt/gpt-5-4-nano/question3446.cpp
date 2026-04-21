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
    getline(cin, s);

    long long cnt = 0;
    for (unsigned char ch : s) {
        if (ch == 'a' || ch == 'A') cnt++;
    }

    cout << cnt << "\n";
    return 0;
}