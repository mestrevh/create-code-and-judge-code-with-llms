/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int homem, acima40;
    if (!(cin >> homem)) return 0;
    if (!(cin >> acima40)) return 0;
    
    bool barato = (!homem) && (acima40 == 1);
    cout << (barato ? 1 : 0) << "\n";
    return 0;
}