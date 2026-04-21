/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int shiftChar(int c, int d) {
    int x = c - 'A';
    x = (x + d) % 26;
    if (x < 0) x += 26;
    return x + 'A';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double A1, A2, B1, B2, C1, C2;
    char M1, M2;
    int D1, D2;

    if (!(cin >> A1 >> A2)) return 0;
    cin >> B1 >> B2;
    cin >> C1 >> C2;
    cin >> M1 >> M2;
    cin >> D1 >> D2;

    double P1 = (A1 + B1 + C1) / 3.0;
    double P2 = (A2 + B2 + C2) / 3.0;

    char F1 = (char)shiftChar(M1, D1);
    char F2 = (char)shiftChar(M2, D2);

    cout.setf(std::ios::fixed);
    cout << setprecision(2);
    cout << "A pista esta na coordenada: (" << P1 << ", " << P2 << ") e o cod e: " << F1 << F2;
    return 0;
}