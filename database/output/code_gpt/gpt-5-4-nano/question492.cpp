/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long totalCapsules = 0;
    long long totalCups = 0;
    long long perProfessor = 0;
    
    for (int i = 0; i < 7; i++) {
        long long qtd;
        char t;
        if (!(cin >> qtd)) return 0;
        cin >> t;
        int size = (t == 'P' || t == 'p') ? 10 : 16;
        totalCapsules += qtd * size;
    }
    
    totalCups = totalCapsules * 2;
    perProfessor = totalCups / 7;
    
    cout << totalCapsules << "\n" << perProfessor;
    return 0;
}