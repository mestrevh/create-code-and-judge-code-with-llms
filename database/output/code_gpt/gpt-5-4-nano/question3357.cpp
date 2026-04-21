/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, P;
    if (!(cin >> N)) return 0;
    cin >> P;
    
    int convidados = 0;
    for (int i = 0; i < N; i++) {
        int X, Y;
        cin >> X >> Y;
        if (X != 0 && Y != 0 && X + Y >= P) convidados++;
    }
    
    cout << convidados << "\n";
    return 0;
}