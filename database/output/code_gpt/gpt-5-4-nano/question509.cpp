/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long x, y;
    if (!(cin >> x)) return 0;
    cin >> y;

    cout << (x > y) << "\n";
    cout << (x == y) << "\n";
    cout << (x < y) << "\n";
    cout << (x != y) << "\n";
    cout << (x >= y) << "\n";
    cout << (x <= y) << "\n";
    
    return 0;
}