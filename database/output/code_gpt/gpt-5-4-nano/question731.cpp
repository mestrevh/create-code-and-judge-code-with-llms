/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    for (int tc = 1; tc <= T; tc++) {
        int N;
        cin >> N;
        vector<int> x(N + 1);
        vector<vector<int>> rev(N + 1);
        for (int i = 1; i <= N; i++) {
            cin >> x[i];
            if (x[i] >= 1 && x[i] <= N) rev[x[i]].push_back(i);
        }

        vector<int> indeg(N + 1, 0);
        for (int v = 1; v <= N; v++) indeg[v] = (int)rev[v].size();

        vector<char> hasSelf(N + 1, 0);
        vector<int> nonSelfCount(N + 1, 0);
        for (int i = 1; i <= N; i++) {
            int v = x[i];
            if (v >= 1 && v <= N) {
                if (i == v) hasSelf[v] = 1;
                else nonSelfCount[v]++;
            }
        }

        int noAlibi = 0, suspicious = 0;

        for (int i = 1; i <= N; i++) {
            bool no = (indeg[i] == 0);
            if (no) noAlibi++;

            bool sus = false;
            if (indeg[i] == 0) {
                sus = true;
            } else {
                int total = indeg[i];
                bool self = hasSelf[i];
                int cntNonSelf = nonSelfCount[i];
                if (total == 1 && self) sus = true;
                if (cntNonSelf > 0) {
                    if (!self) sus = true;
                    else {
                        if (cntNonSelf == total - 1) sus = true;
                    }
                    if (self && cntNonSelf >= 1) sus = true;
                }
            }

            if (sus) suspicious++;
        }

        cout << "Caso #" << tc << ": " << noAlibi << " " << suspicious << "\n";
    }
    return 0;
}