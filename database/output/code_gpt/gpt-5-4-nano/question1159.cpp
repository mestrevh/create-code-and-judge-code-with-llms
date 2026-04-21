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
    long long V = P / 3;
    long long F = P % 3;
    cout << V << "\n" << F << "\n";
    return 0;
}