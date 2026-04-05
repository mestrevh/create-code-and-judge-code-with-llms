/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int w;
    if (!(cin >> w)) return 0;
    cout << ((w % 2 == 0 && w >= 2) ? "YES" : "NO");
    return 0;
}