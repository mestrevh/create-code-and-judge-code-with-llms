/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long X, Y;
    if (!(cin >> N)) return 0;
    cin >> X >> Y;

    if (X == 0) {
        long long total = 0;
        for (long long i = 0; i < Y; i++) {
            string w;
            long long z;
            cin >> w >> z;
            total += z;
        }
        long long missing = 50 - total;
        if (missing > 0) {
            cout << "Ainda nao foram vendidas latas suficientes. Faltam " << missing << " latas.";
        } else {
            long long win = 50;
            cout << "Quem levou a cesta basica foi o " << win << "* cliente atendido por coragem, as ";
            cout << "00:00. Que comprou 1 lata.";
        }
        return 0;
    }

    long long people1 = N / X;
    long long baseCount = people1;
    long long missing = 50 - baseCount;

    vector<pair<string,long long>> rec;
    rec.reserve((size_t)Y);
    for (long long i = 0; i < Y; i++) {
        string w;
        long long z;
        cin >> w >> z;
        rec.push_back({w, z});
    }

    if (missing > 0) {
        cout << "Ainda nao foram vendidas latas suficientes. Faltam " << missing << " latas.";
        return 0;
    }

    long long winnerClient = -1;
    string winnerTime;
    long long winnerLatas = 1;

    long long count = 0;
    for (int client = 1; client <= N; client++) {
        bool isMultiX = (X != 0 && client % X == 0);
        long long cans = 1;
        if (isMultiX) {
            size_t idx = (size_t)(client / X - 1);
            if (idx < rec.size()) cans = rec[idx].second;
            else cans = 1;
        }
        else {
            if (client % X == 0) cans = 1;
        }

        if (client % X == 0) {
            size_t idx = (size_t)(client / X - 1);
            if (idx < rec.size()) {
                winnerTime = rec[idx].first;
                winnerLatas = cans;
            } else {
                winnerTime = "00:00";
                winnerLatas = cans;
            }
        }

        if (count < 50 && count + cans >= 50) {
            winnerClient = client;
            if (client % X == 0) {
                size_t idx = (size_t)(client / X - 1);
                if (idx < rec.size()) {
                    winnerTime = rec[idx].first;
                    winnerLatas = cans;
                } else {
                    winnerTime = "00:00";
                    winnerLatas = 1;
                }
            } else {
                winnerTime = "00:00";
                winnerLatas = cans;
            }
            break;
        }
        count += cans;
    }

    cout << "Quem levou a cesta basica foi o " << winnerClient << "* cliente atendido por coragem, as " << winnerTime
         << ". Que comprou " << winnerLatas << " lata";
    if (winnerLatas != 1) cout << "s";
    cout << ".";
    return 0;
}