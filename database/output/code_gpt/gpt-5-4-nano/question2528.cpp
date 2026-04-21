/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    if (!(cin >> n)) return 0;
    vector<string> dias = {"domingo", "segunda", "terca", "quarta", "quinta", "sexta", "sabado"};
    if (n >= 1 && n <= 7) cout << dias[n - 1];
    return 0;
}