/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long P;
    if (!(cin >> P)) return 0;
    
    cout << P / 3 << "\n" << P % 3 << "\n";
    return 0;
}