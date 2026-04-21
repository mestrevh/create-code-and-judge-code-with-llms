/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long A, B, C, D;
    if (!(cin >> A >> B >> C >> D)) return 0;

    bool cond = (B > C) && (D > A) && (C + D > A + B) && (C > 0) && (D > 0) && (A % 2 == 0);

    cout << (cond ? "Valores aceitos" : "Valores nao aceitos");
    return 0;
}