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
    if (!(cin >> N)) return 0;

    cout << fixed << setprecision(2);

    for (int t = 1; t <= N; t++) {
        double V;
        cin >> V;
        string line;
        getline(cin, line);
        vector<string> fruits;

        getline(cin, line);
        {
            stringstream ss(line);
            string s;
            while (ss >> s) fruits.push_back(s);
        }

        int totalKg = (int)fruits.size();
        for (int d = 0; d < totalKg; d++) {
            cout << "dia " << (d + 1) << ": " << 1 << " kg\n";
        }

        long long totalMoneyCents = llround(V * 100.0);
        double avgKg = (double)totalKg / (double)totalKg;
        double avgMoney = (double)totalMoneyCents / 100.0 / (double)totalKg;

        cout << avgKg << " kg por dia\n";
        cout << "R$ " << avgMoney << " por dia";
        if (t < N) cout << "\n";
    }

    cout << "\n";
    return 0;
}