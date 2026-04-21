/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> teams(8);
    for (int i = 0; i < 8; ++i) {
        if (!(cin >> teams[i])) break;
    }

    vector<int> qf_indices(8);
    for (int i = 0; i < 8; ++i) {
        if (!(cin >> qf_indices[i])) break;
    }

    vector<char> qf_results(4);
    for (int i = 0; i < 4; ++i) {
        if (!(cin >> qf_results[i])) break;
    }

    vector<char> sf_results(2);
    for (int i = 0; i < 2; ++i) {
        if (!(cin >> sf_results[i])) break;
    }

    char final_result;
    cin >> final_result;

    vector<string> qf_winners(4);
    for (int i = 0; i < 4; ++i) {
        string team1 = teams[qf_indices[2 * i]];
        string team2 = teams[qf_indices[2 * i + 1]];
        cout << "Quartas de final " << i + 1 << ": " << team1 << " x " << team2 << "\n";
        if (qf_results[i] == 'A') {
            qf_winners[i] = team1;
        } else {
            qf_winners[i] = team2;
        }
    }

    vector<string> sf_winners(2);
    for (int i = 0; i < 2; ++i) {
        string q1 = qf_winners[2 * i];
        string q2 = qf_winners[2 * i + 1];
        cout << "Semifinal " << i + 1 << ": " << q1 << " x " << q2 << "\n";
        if (sf_results[i] == 'X') {
            sf_winners[i] = q1;
        } else {
            sf_winners[i] = q2;
        }
    }

    string s1 = sf_winners[0];
    string s2 = sf_winners[1];
    cout << "Final: " << s1 << " x " << s2 << "\n";

    string champion;
    if (final_result == '#') {
        champion = s1;
    } else {
        champion = s2;
    }

    cout << "O vencedor da competição de futebol de robôs foi " << champion << "!" << endl;

    return 0;
}