/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long A, B;
    if (!(cin >> A >> B)) return 0;
    string s;
    cin >> s;

    long long cur = A % B;
    long long ans = 1 % B;

    for (char ch : s) {
        if (ch == '1') {
            ans = (ans * cur) % B;
        }
        cur = (cur * cur) % B;
    }

    cout << ans % B;
    return 0;
}