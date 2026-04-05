/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C;
    if (!(cin >> A >> B >> C)) return 0;
    vector<pair<char,int>> v{{'A',A},{'B',B},{'C',C}};
    for (auto [ch,val] : v) {
        bool othersSame = true;
        for (auto [ch2,val2] : v) {
            if (ch2 == ch) continue;
            if (val2 != val) { othersSame = false; break; }
        }
        if (!othersSame) continue;
        bool unique = true;
        for (auto [ch2,val2] : v) {
            if (ch2 == ch) continue;
            if (val2 == val) unique = false;
        }
        if (unique) {
            cout << ch << "\n";
            return 0;
        }
    }
    int cnt1 = (A==1) + (B==1) + (C==1);
    if (cnt1==1) {
        if (A==1) cout << 'A' << "\n";
        else if (B==1) cout << 'B' << "\n";
        else cout << 'C' << "\n";
    } else if (cnt1==2) {
        if (A==0) cout << 'A' << "\n";
        else if (B==0) cout << 'B' << "\n";
        else cout << 'C' << "\n";
    } else {
        cout << "*\n";
    }
    return 0;
}