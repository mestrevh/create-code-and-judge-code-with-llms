/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int code;
    int bestCode = -1;
    int bestCount = -1;
    
    while (cin >> code) {
        if (code == 9999) break;
        string dna;
        cin >> dna;
        int cntT = 0;
        for (char c : dna) if (c == 'T') cntT++;
        if (cntT > bestCount) {
            bestCount = cntT;
            bestCode = code;
        }
    }
    
    if (bestCode != -1) cout << bestCode;
    return 0;
}