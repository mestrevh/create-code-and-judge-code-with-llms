/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long A, B, C, D;
    if (!(cin >> A >> B >> C >> D)) return 0;
    long long diff = (A * B) - (C * D);
    cout << "DIFERENCA = " << diff;
    return 0;
}