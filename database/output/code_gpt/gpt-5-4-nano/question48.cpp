/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    if (!(cin >> n)) return 0;
    
    if (n % 10 == 0) {
        cout << "NAO";
        return 0;
    }
    
    int last = n % 10;
    int m = n / 10;
    if (last != 0 && n % last == 0 && m != 0 && n % m == 0) {
        cout << "SIM";
    } else {
        cout << "NAO";
    }
    return 0;
}