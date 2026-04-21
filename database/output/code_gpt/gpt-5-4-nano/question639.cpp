/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int F, P, E, A;
    while ( (cin >> F >> P >> E >> A) ) {
        if (F==0 && P==0 && E==0 && A==0) break;

        vector<vector<long long>> t(P+1, vector<long long>(F+1));
        vector<vector<long long>> en(P+1, vector<long long>(F+1));

        for (int p=1; p<=P; p++) {
            for (int f=1; f<=F; f++) cin >> en[p][f] >> t[p][f];
        }

        const long long INF = (1LL<<62);
        vector<long long> prev(F+1, INF), cur(F+1, INF);

        prev[1] = en[1][1] * t[1][1];

        for (int f=2; f<=F; f++) {
            prev[f] = INF;
        }

        if (P >= 2) {
            for (int f=1; f<=F; f++) {
                if (f != 1) {
                    long long val = (en[1][f] + (long long)E) * (t[1][f] + (long long)A);
                    prev[f] = val;
                } else {
                    prev[f] = en[1][1] * t[1][1];
                }
            }
        }

        for (int p=2; p<=P; p++) {
            fill(cur.begin(), cur.end(), INF);
            for (int fp=1; fp<=F; fp++) {
                if (prev[fp] >= INF/2) continue;
                for (int f=1; f<=F; f++) {
                    long long addEnergy = en[p][f];
                    long long addTime = t[p][f];
                    long long val;
                    if (fp == f) {
                        val = prev[fp] + addEnergy * addTime;
                    } else {
                        val = prev[fp] + (addEnergy + (long long)E) * (addTime + (long long)A);
                    }
                    cur[f] = min(cur[f], val);
                }
            }
            prev.swap(cur);
        }

        long long ans = *min_element(prev.begin()+1, prev.end());
        cout << ans << "\n";
    }
    return 0;
}