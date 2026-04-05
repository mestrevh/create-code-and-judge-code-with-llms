/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int A, M;
    if (!(cin >> A)) return 0;
    if (!(cin >> M)) return 0;
    
    int B = 2 * M - A;
    cout << B << "\n";
    return 0;
}