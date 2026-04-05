/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int h, m;
    if (!(cin >> h >> m)) return 0;
    int total = h * 60 + m;
    cout << total << " minutos.\n";
    return 0;
}