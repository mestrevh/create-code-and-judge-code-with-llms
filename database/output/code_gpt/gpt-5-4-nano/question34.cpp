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
    
    long long notes50 = n / 50; n %= 50;
    long long notes20 = n / 20; n %= 20;
    long long notes10 = n / 10; n %= 10;
    long long notes5 = n / 5; n %= 5;
    long long notes1 = n;
    
    cout << "Notas de 50: " << notes50 << "\n";
    cout << "Notas de 20: " << notes20 << "\n";
    cout << "Notas de 10: " << notes10 << "\n";
    cout << "Notas de 5: " << notes5 << "\n";
    cout << "Notas de 1: " << notes1 << "\n";
    
    return 0;
}