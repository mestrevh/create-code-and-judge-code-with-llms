/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct CmdRes {
    int idx;
    vector<string> played;
    double total;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;

    for (int tc = 1; tc <= T; tc++) {
        int M;
        cin >> M;

        vector<string> song(M);
        vector<double> dur(M);
        for (int i = 0; i < M; i++) {
            cin >> song[i];
            cin >> dur[i];
        }

        string commands;
        cin >> commands;

        int idx = 0;
        bool running = true;
        vector<string> played;
        double total = 0.0;

        for (char c : commands) {
            if (!running) break;
            if (c == 's') {
                running = false;
                break;
            }
            if (c == 'r') {
                played.push_back(song[idx]);
                total += dur[idx];
            } else if (c == 'v') {
                played.push_back(song[idx]);
                total += dur[idx];
            } else if (c == 'p') {
            }
            idx = (idx + 1) % M;
        }

        cout << "Viagem " << tc << ": " << setprecision(16) << total << "\n";
        for (size_t i = 0; i < played.size(); i++) {
            if (i) cout << ", ";
            cout << played[i];
        }
        cout << "\n";
    }
    return 0;
}