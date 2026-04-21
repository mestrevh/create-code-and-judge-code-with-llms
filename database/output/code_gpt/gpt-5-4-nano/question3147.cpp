/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

void troca(int &A, int &B) {
    if (A > B) swap(A, B);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int A, B;
    if (!(cin >> A >> B)) return 0;
    troca(A, B);
    cout << A << " " << B;
    return 0;
}