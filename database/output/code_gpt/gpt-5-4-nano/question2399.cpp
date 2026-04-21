/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int h1, m1, h2, m2;
    if (!(cin >> h1 >> m1 >> h2 >> m2)) return 0;
    
    int start = h1 * 60 + m1;
    int end = h2 * 60 + m2;
    int diff = end - start;
    if (diff <= 0) diff += 24 * 60;
    
    int hh = diff / 60;
    int mm = diff % 60;
    
    cout << "O JOGO DUROU " << hh << " HORA(S) E " << mm << " MINUTO(S)";
    return 0;
}