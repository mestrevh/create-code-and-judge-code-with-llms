/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<string> teams(8);
    for (int i = 0; i < 8; ++i)
        cin >> teams[i];

    vector<pair<int, int>> matches(4);
    for (int i = 0; i < 4; ++i) {
        int a, b;
        cin >> a >> b;
        matches[i] = {a, b};
    }

    char quarterWinners[4];
    for (int i = 0; i < 4; ++i)
        cin >> quarterWinners[i];

    char semiWinners[2];
    for (int i = 0; i < 2; ++i)
        cin >> semiWinners[i];

    char finalWinner;
    cin >> finalWinner;

    for (int i = 0; i < 4; ++i) {
        int a = matches[i].first;
        int b = matches[i].second;
        cout << "Quartas de final " << i + 1 << ": " << teams[a] << " x " << teams[b] << endl;
    }

    cout << "Semifinal 1: " << (quarterWinners[0] == 'A' ? teams[matches[0].first] : teams[matches[0].second])
         << " x " << (quarterWinners[1] == 'A' ? teams[matches[1].first] : teams[matches[1].second]) << endl;
    cout << "Semifinal 2: " << (quarterWinners[2] == 'A' ? teams[matches[2].first] : teams[matches[2].second])
         << " x " << (quarterWinners[3] == 'A' ? teams[matches[3].first] : teams[matches[3].second]) << endl;

    cout << "Final: " << (semiWinners[0] == 'X' ? (quarterWinners[0] == 'A' ? teams[matches[0].first] : teams[matches[0].second]) : (quarterWinners[1] == 'A' ? teams[matches[1].first] : teams[matches[1].second]))
         << " x " << (semiWinners[1] == 'X' ? (quarterWinners[2] == 'A' ? teams[matches[2].first] : teams[matches[2].second]) : (quarterWinners[3] == 'A' ? teams[matches[3].first] : teams[matches[3].second])) << endl;

    cout << "O vencedor da competição de futebol de robôs foi " << (finalWinner == '#' ? (semiWinners[0] == 'X' ? (quarterWinners[0] == 'A' ? teams[matches[0].first] : teams[matches[0].second]) : (quarterWinners[1] == 'A' ? teams[matches[1].first] : teams[matches[1].second])) : (finalWinner == '%' ? (semiWinners[0] == 'X' ? (quarterWinners[0] == 'A' ? teams[matches[0].first] : teams[matches[0].second]) : (quarterWinners[1] == 'A' ? teams[matches[1].first] : teams[matches[1].second])) : (semiWinners[1] == 'Y' ? (quarterWinners[2] == 'A' ? teams[matches[2].first] : teams[matches[2].second]) : (quarterWinners[3] == 'A' ? teams[matches[3].first] : teams[matches[3].second]))) : '#') << "!" << endl;

    return 0;
}
