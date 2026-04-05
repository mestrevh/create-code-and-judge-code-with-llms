/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int A, B, C;
    if (!(cin >> A >> B >> C)) return 0;
    
    bool sad = false;
    if (B > A) {
        if (C <= B) sad = true;
        else if (C - B < B - A) sad = true;
    } else if (B == A) {
        if (C < B) sad = true;
    } else {
        if (C < B) {
            if (B - C >= A - B) sad = true;
        }
    }
    
    cout << (sad ? ":(" : ":)");
    return 0;
}