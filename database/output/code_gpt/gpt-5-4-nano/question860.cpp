/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n;
    if (!(cin >> n)) return 0;
    
    if (n < 0) n = 0;
    long long horseshoes = n * 4;
    
    cout << "Numero de ferraduras a serem compradas: " << horseshoes;
    return 0;
}