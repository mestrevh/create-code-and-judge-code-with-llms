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

        vector<int> ids;
        vector<double> temps;
        vector<char> smoke;
        ids.reserve(N);
        temps.reserve(N);
        smoke.reserve(N);

        for (int i = 0; i < N; i++) {
            int id;
            double temp;
            char s;
            cin >> id >> temp >> s;
            ids.push_back(id);
            temps.push_back(temp);
            smoke.push_back(s);
        }

        double sum = 0.0;
        for (double x : temps) sum += x;
        double avg = (N == 0 ? 0.0 : sum / N);

        const double eps = 1e-12;

        vector<int> activated;
        for (int i = 0; i < N; i++) {
            double ti = temps[i];
            bool noFire = (smoke[i] == 'N');
            if (!noFire) {
                activated.push_back(ids[i]);
                continue;
            }

            bool cond1 = (ti <= avg + eps); 
            bool cond2 = (ti >= 0.0); 
            bool cond3 = (ti < 40.0 - eps);
            bool cond4 = (ti <= avg * 1.15 + eps);

            if (cond1 || !cond3 || !cond4) {
                activated.push_back(ids[i]);
                continue;
            }
        }

        cout << "TESTE " << tc << "\n";
        for (int i = 0; i < (int)activated.size(); i++) {
            cout << activated[i] << "\n";
        }
    }
    return 0;
}