/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M;
    if (!(cin >> M)) return 0;
    double V1, V2;
    cin >> V1 >> V2;

    vector<vector<double>> A(M, vector<double>(M)), B(M, vector<double>(M));
    for (int i = 0; i < M; i++) for (int j = 0; j < M; j++) cin >> A[i][j];
    for (int i = 0; i < M; i++) for (int j = 0; j < M; j++) cin >> B[i][j];

    double attackR = 0, defendR = 0, attackK = 0, defendK = 0;
    for (int i = 0; i < M; i++) {
        attackR += A[i][i];
        defendR += A[i][M - 1 - i];
        attackK += B[i][i];
        defendK += B[i][M - 1 - i];
    }

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        char r, k;
        cin >> r >> k;
        if (r == 'A' && k == 'A') {
            double mx = max(attackR, attackK);
            double mn = min(attackR, attackK);
            if (attackR < attackK) V1 -= (mx - mn);
            else V2 -= (mx - mn);
        } else if (r == 'A' && k == 'D') {
            if (attackR > defendK) {
                double loss = (attackR - defendK) / 2.0;
                V2 -= loss;
            }
        } else if (r == 'D' && k == 'A') {
            if (attackK > defendR) {
                double loss = (attackK - defendR) / 2.0;
                V1 -= loss;
            }
        }
    }

    double eps = 1e-9;
    if (V1 > V2 + eps) cout << "Ryu ganhou a batalha.";
    else if (V2 > V1 + eps) cout << "Ken ganhou a batalha.";
    else cout << "Houve empate.";
    return 0;
}