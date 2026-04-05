/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    if (!(cin >> N)) return 0;
    string gabarito, candidato;
    cin >> gabarito >> candidato;
    
    int acertos = 0;
    for (int i = 0; i < N; i++) {
        if (gabarito[i] == candidato[i]) acertos++;
    }
    
    cout << acertos << "\n";
    return 0;
}