/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int M, A, B;
    if (!(cin >> M)) return 0;
    cin >> A >> B;
    
    int C = M - A - B;
    int oldest = max({A, B, C});
    cout << oldest << "\n";
    return 0;
}