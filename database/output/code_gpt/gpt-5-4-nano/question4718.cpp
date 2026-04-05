/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

long long subtrair(long long a, long long b) {
    return a - b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long a, b;
    if (!(cin >> a)) return 0;
    cin >> b;
    cout << subtrair(a, b);
    return 0;
}