/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    if (!(cin >> N)) return 0;
    int d1 = N / 100;
    int d3 = N % 10;
    int d2 = (N / 10) % 10;
    
    cout << d1 << ' ' << d2 << ' ' << d3;
    return 0;
}