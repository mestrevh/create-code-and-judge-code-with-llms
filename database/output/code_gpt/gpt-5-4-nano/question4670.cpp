/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Student {
    int periods;
    long double avg;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V;
    if (!(cin >> V)) return 0;

    int p;
    cin >> p;
    long double sumC = 0;
    for (int i = 0; i < p; i++) {
        long double x;
        cin >> x;
        sumC += x;
    }
    long double avgC = sumC / p;

    int C;
    cin >> C;
    vector<Student> all;
    all.reserve(C + 1);

    all.push_back({p, avgC});

    for (int i = 0; i < C; i++) {
        int cp;
        cin >> cp;
        long double sum = 0;
        for (int j = 0; j < cp; j++) {
            long double x;
            cin >> x;
            sum += x;
        }
        long double avg = sum / cp;
        all.push_back({cp, avg});
    }

    auto cmp = [](const Student& a, const Student& b) {
        if (fabsl(a.avg - b.avg) > 1e-12L) return a.avg > b.avg;
        return a.periods > b.periods;
    };

    sort(all.begin(), all.end(), cmp);

    int rank = 1;
    int indexC = -1;
    for (int i = 0; i < (int)all.size(); i++) {
        if (fabsl(all[i].avg - avgC) <= 1e-12L && all[i].periods == p) {
            indexC = i;
            rank = i + 1;
            break;
        }
    }

    if (indexC == -1) {
        for (int i = 0; i < (int)all.size(); i++) {
            if (fabsl(all[i].avg - avgC) <= 1e-12L && all[i].periods > 0 && all[i].periods == p) {
                rank = i + 1;
                break;
            }
        }
    }

    if (rank <= V) {
        cout << "Matriculado, seu ranking é " << rank << " dentre as " << V << " vagas";
    } else {
        cout << "Se não tivesse pago Dominó " << p << ", teria entrado...";
    }

    return 0;
}