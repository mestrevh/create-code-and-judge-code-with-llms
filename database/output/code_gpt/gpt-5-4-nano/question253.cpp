/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string a, b;
    if (!getline(cin, a)) return 0;
    if (!getline(cin, b)) return 0;

    if (a == b) cout << "IGUAIS\n";
    else cout << "DIFERENTES\n";
    return 0;
}