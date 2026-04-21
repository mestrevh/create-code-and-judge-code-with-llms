/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long C, N;
    if (!(cin >> C >> N)) return 0;

    if (C <= 0) {
        for (long long i = 0; i < N; i++) {
            long long a; 
            if (!(cin >> a)) return 0;
            for (int j = 0; j < 4; j++) {
                long long x; cin >> x;
            }
        }
        cout << "Nao possuem caminhoes para fazer a coleta!\n";
        return 0;
    }

    long long totalL = 0;
    long long totalP_m3 = 0;
    long long totalL_mL = 0;
    long long totalM_mL = 0;

    long long apartments;
    for (long long i = 0; i < N; i++) {
        if (!(cin >> apartments)) return 0;
        long long L, P_m3, Pl, M_mL;
        cin >> L >> P_m3 >> Pl >> M_mL;
        if (apartments > 0) {
            totalL += L * apartments;
            totalP_m3 += P_m3 * apartments;
            totalL += 0;
            totalP_m3 += 0;
            totalL_mL += Pl * apartments;
            totalM_mL += M_mL * apartments;
        }
    }

    long long total_m3 = 0;
    total_m3 = totalP_m3;
    long long vidro_m3 = (totalL + 1000000LL - 1) / 1000000LL;
    long long plast_m3 = (totalL_mL + 1000000LL - 1) / 1000000LL;
    long long metal_m3 = (totalM_mL + 1000000LL - 1) / 1000000LL;

    total_m3 += vidro_m3 + plast_m3 + metal_m3;

    long long capacidade_por_viagem_total = C * 3;
    if (capacidade_por_viagem_total <= 0) {
        cout << "Nao possuem caminhoes para fazer a coleta!\n";
        return 0;
    }

    long long viagens_total = (total_m3 + 3 - 1) / 3;
    if (viagens_total <= 0) {
        cout << 0 << "\n";
        return 0;
    }

    long long media_por_caminhao = (viagens_total + C - 1) / C;
    cout << media_por_caminhao << "\n";
    return 0;
}