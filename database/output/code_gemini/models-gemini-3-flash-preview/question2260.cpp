/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> names(8);
    for (int i = 0; i < 8; ++i) {
        if (!getline(cin, names[i])) break;
        if (names[i].empty() || names[i] == "\r") {
            i--;
            continue;
        }
        while (!names[i].empty() && (names[i].back() == '\r' || names[i].back() == '\n')) {
            names[i].pop_back();
        }
    }

    vector<int> idx(8);
    for (int i = 0; i < 8; ++i) {
        if (!(cin >> idx[i])) break;
    }

    vector<string> q_res(4);
    for (int i = 0; i < 4; ++i) {
        cin >> q_res[i];
    }

    vector<string> s_res(2);
    for (int i = 0; i < 2; ++i) {
        cin >> s_res[i];
    }

    string f_res;
    cin >> f_res;

    cout << "Bem vindos ao Exame Chunnin!\n";

    vector<string> q_winners(4);
    for (int i = 0; i < 4; ++i) {
        string n1 = names[idx[2 * i]];
        string n2 = names[idx[2 * i + 1]];
        cout << "Quartas de final " << i + 1 << ": " << n1 << " x " << n2 << "\n";
        if (q_res[i] == "A") {
            q_winners[i] = n1;
        } else {
            q_winners[i] = n2;
        }
    }

    vector<string> s_winners(2);
    for (int i = 0; i < 2; ++i) {
        string n1 = q_winners[2 * i];
        string n2 = q_winners[2 * i + 1];
        cout << "Semifinal " << i + 1 << ": " << n1 << " x " << n2 << "\n";
        if (s_res[i] == "X") {
            s_winners[i] = n1;
        } else {
            s_winners[i] = n2;
        }
    }

    string final_n1 = s_winners[0];
    string final_n2 = s_winners[1];
    cout << "Final: " << final_n1 << " x " << final_n2 << "\n";
    
    string champion;
    if (f_res == "#") {
        champion = final_n1;
    } else {
        champion = final_n2;
    }

    cout << "O grande vencedor e " << champion << "!\n";

    return 0;
}