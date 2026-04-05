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

    if (A < 0 || B < 0 || C < 0) {
        cout << "esses dados nao valem";
        return 0;
    }

    bool sad = false;

    if ((B > A || B == A) && (C < B || C == B)) {
        if (B > A && C <= B) sad = true;
    }

    if (!sad) {
        if (B > A && C > B) {
            int inc1 = B - A;
            int inc2 = C - B;
            if (inc2 < inc1) sad = true;
        }
    }

    if (!sad) {
        if (B < A && C < B) {
            int dec1 = A - B;
            int dec2 = B - C;
            if (dec2 >= dec1) sad = true;
        }
    }

    if (!sad) {
        if (B == A && C < B) sad = true;
    }

    if (!sad) cout << ":)";
    else cout << ":(";

    return 0;
}