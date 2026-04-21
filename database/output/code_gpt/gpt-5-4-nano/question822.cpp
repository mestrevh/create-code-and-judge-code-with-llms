/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long D, P, U, N;
    if (!(cin >> D >> P >> U >> N)) return 0;
    cout << (D + (P - D) + U + N) << "\n";
    return 0;
}