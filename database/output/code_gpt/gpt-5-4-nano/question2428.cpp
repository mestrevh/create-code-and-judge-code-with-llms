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
    
    long long a = n % 10;
    long long b = (n / 10) % 10;
    long long c = n / 100;
    
    long long inv = a * 100 + b * 10 + c;
    cout << inv;
    return 0;
}