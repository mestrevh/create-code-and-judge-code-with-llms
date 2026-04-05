/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long a, b;
    if (!(cin >> a >> b)) return 0;
    if (a <= b) {
        cout << a << "\n" << b << "\n";
    } else {
        cout << b << "\n" << a << "\n";
    }
    return 0;
}