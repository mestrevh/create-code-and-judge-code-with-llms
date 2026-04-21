/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string team;
    if (!(cin >> team)) return 0;

    vector<string> preferred = {"GSW", "HOU", "CLE", "BOS"};

    auto isPreferred = [&](const string& t) {
        for (const auto& p : preferred) if (p == t) return true;
        return false;
    };

    if (!isPreferred(team)) {
        cout << "Nenhum time de interesse jogando.";
        return 0;
    }

    string player;
    long long att2, conv2, att3, conv3;
    cin >> ws;
    getline(cin, player);
    if (player.empty()) getline(cin, player);
    cin >> att2 >> conv2 >> att3 >> conv3;

    long long totalPoints = 2 * (conv2 + 3 * conv3 / 3); 
    totalPoints = 2 * conv2 + 3 * conv3;

    double pct2 = (att2 > 0) ? (100.0 * conv2 / att2) : 0.0;
    double pct3 = (att3 > 0) ? (100.0 * conv3 / att3) : 0.0;

    bool good = false;
    if (totalPoints > 30) good = true;
    if (pct2 > 50.0 && att2 > 10) good = true;
    if (pct3 > 40.0 && att3 > 7) good = true;

    if (good) {
        cout << "O time " << team << " estah jogando, e " << player << " estah indo bem.";
    } else {
        cout << "O time " << team << " estah jogando, mas " << player << " nao estah indo bem.";
    }

    return 0;
}