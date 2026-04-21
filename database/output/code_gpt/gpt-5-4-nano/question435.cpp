/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long minutosPorProcesso;
    if (!(cin >> minutosPorProcesso)) return 0;
    
    long long totalMinutos = 8LL * 60LL;
    cout << (totalMinutos / minutosPorProcesso);
    return 0;
}