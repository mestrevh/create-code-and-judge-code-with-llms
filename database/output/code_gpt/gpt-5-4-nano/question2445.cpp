/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    if (!(cin >> N)) return 0;
    long long D;
    cin >> D;

    long long bestP = LLONG_MIN;
    long long bestIndex = 1;
    long long bestQ = 0;

    for (long long i = 1; i <= N; i++) {
        long long K, B;
        cin >> K >> B;

        long long P = (K * D + B) / 100;
        long long Qnum = P - D;
        long long Q;

        if (D == 0) {
            Q = (P == 0) ? 0 : LLONG_MAX / 2;
        } else {
            long long num = Qnum * 100;
            if (num >= 0) {
                Q = (num + D - 1) / D;
            } else {
                Q = num / D;
            }
        }

        cout << "ELEMENTO #" << i << "\n";
        cout << "DANO: " << P << "\n";
        cout << "AUMENTO: " << Q << "%\n";

        if (i != N) cout << "\n";

        if (P > bestP) {
            bestP = P;
            bestIndex = i;
            bestQ = Q;
        }
    }

    cout << "\n";
    cout << "ELEMENTO ESCOLHIDO: #" << bestIndex << "\n";
    cout << "NOVO DANO DA ESPADA: " << bestP << "\n";
    cout << "AUMENTO: " << bestQ << "%";

    return 0;
}