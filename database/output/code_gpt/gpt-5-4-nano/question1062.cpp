/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    double ph;
    if (!(cin >> ph)) return 0;

    if (ph > 7.0) cout << "Basica";
    else if (ph < 7.0) cout << "Acida";
    else cout << "Neutra";
    return 0;
}