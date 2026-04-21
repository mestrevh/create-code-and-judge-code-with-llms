/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> ninjas(8);
    for (int i = 0; i < 8; i++) {
        getline(cin, ninjas[i]);
        if (ninjas[i].size() == 0 && cin.eof()) return 0;
        if (!cin && ninjas[i].empty()) i--;
    }

    vector<pair<int,int>> fights4(4);
    for (int i = 0; i < 4; i++) {
        int a, b;
        cin >> a >> b;
        fights4[i] = {a,b};
    }

    vector<string> q(4);
    for (int i = 0; i < 4; i++) cin >> q[i];

    vector<string> s(2);
    for (int i = 0; i < 2; i++) cin >> s[i];

    string f;
    cin >> f;

    auto pick = [&](int idx1, int idx2, const string& t) -> int {
        if (t == "A" || t == "X" || t == "#") return idx1;
        return idx2;
    };

    int w4[4];
    for (int i = 0; i < 4; i++) w4[i] = pick(fights4[i].first, fights4[i].second, q[i]);

    int wS1 = (s[0] == "X") ? w4[0] : w4[1];
    int wS2 = (s[1] == "X") ? w4[2] : w4[3];

    int wF = (f == "#") ? wS1 : wS2;

    cout << "Bem vindos ao Exame Chunnin!" << "\n";
    for (int i = 0; i < 4; i++) {
        cout << "Quartas de final " << (i+1) << ": " << ninjas[fights4[i].first] << " x " << ninjas[fights4[i].second] << "\n";
    }
    cout << "Semifinal 1: " << ninjas[w4[0]] << " x " << ninjas[w4[1]] << "\n";
    cout << "Semifinal 2: " << ninjas[w4[2]] << " x " << ninjas[w4[3]] << "\n";
    cout << "Final: " << ninjas[wS1] << " x " << ninjas[wS2] << "\n";
    cout << "O grande vencedor e " << ninjas[wF] << "!" << "\n";

    return 0;
}