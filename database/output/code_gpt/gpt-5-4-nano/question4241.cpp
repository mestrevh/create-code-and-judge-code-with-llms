/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<string> names(n);
    vector<array<double,3>> score(n);

    const double wMotor = 5, wSusp = 2, wTurbo = 3;
    vector<double> perf(n);

    for (int i = 0; i < n; i++) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, names[i]);
        double m, s, t;
        cin >> m >> s >> t;
        score[i] = {m, s, t};
        perf[i] = (m * wMotor + s * wSusp + t * wTurbo) / (wMotor + wSusp + wTurbo);
    }

    double sum = 0.0;
    for (int i = 0; i < n; i++) sum += perf[i];
    double avg = sum / n;

    bool first = true;
    for (int i = 0; i < n; i++) {
        if (perf[i] + 1e-9 >= avg) {
            if (!first) cout << "\n";
            cout << names[i];
            first = false;
        }
    }
    return 0;
}