/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

bool canBuy(long long C, long long M, long long P);

long long moneyNeeded(long long C, long long P) {
    if (C <= 0) return 0;
    if (C == 1) return P;
    long long half = C / 2;
    long long rest = C - half;
    long long a = moneyNeeded(half, P);
    long long b = moneyNeeded(rest, P);
    return a + b;
}

bool canBuy(long long C, long long M, long long P) {
    if (C <= 0) return true;
    if (P < 0 || M < 0) return false;
    long long need = moneyNeeded(C, P);
    return M >= need;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long C, M, P;
    bool firstOutput = true;
    while (cin >> C >> M >> P) {
        bool ok = canBuy(C, M, P);
        cout << (ok ? "Sim" : "Nao");
        if (!cin.eof()) cout << "\n";
    }
    return 0;
}