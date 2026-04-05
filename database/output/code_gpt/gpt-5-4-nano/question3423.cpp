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

    long long odd = 1;
    long long root = 0;
    while (n > 0) {
        n -= odd;
        odd += 2;
        root++;
    }

    cout << root << "\n";
    return 0;
}