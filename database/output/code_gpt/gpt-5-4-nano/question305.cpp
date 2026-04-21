/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long N;
    if (!(cin >> N)) return 0;
    
    long long h = N / 3600;
    long long m = (N % 3600) / 60;
    long long s = N % 60;
    
    cout << h << ":" << m << ":" << s;
    return 0;
}