/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long a, b, s;
    if (!(cin >> a >> b >> s)) return 0;

    long long dist = llabs(a) + llabs(b);
    if (dist > s) {
        cout << "No";
        return 0;
    }
    cout << (( (s - dist) % 2 == 0) ? "Yes" : "No");
    return 0;
}