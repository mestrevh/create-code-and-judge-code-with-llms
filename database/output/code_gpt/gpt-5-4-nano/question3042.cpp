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
    
    bool happy = false;

    if (B < A && C >= B) happy = true;
    if (B > A && C > B) {
        int inc12 = B - A;
        int inc23 = C - B;
        if (inc23 >= inc12) happy = true;
    }
    if (B < A && C < B) {
        int dec12 = A - B;
        int dec23 = B - C;
        if (dec23 < dec12) happy = true;
    }
    if (B == A && C > B) happy = true;

    cout << (happy ? ":)" : ":(");
    return 0;
}