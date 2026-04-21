/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int estudante, idoso;
    if (!(cin >> estudante)) return 0;
    if (!(cin >> idoso)) return 0;
    
    cout << ((estudante == 1 || idoso == 1) ? 1 : 0) << "\n";
    return 0;
}