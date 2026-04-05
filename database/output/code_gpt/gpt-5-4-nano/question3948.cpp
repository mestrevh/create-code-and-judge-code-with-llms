/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A;
    if (!(cin >> A)) return 0;

    unordered_map<int, string> monitorName;
    for (int i = 0; i < A; i++) {
        int id;
        string name;
        cin >> id >> ws;
        getline(cin, name);
        monitorName[id] = name;
    }

    int B;
    cin >> B;

    for (int i = 0; i < B; i++) {
        string aluno;
        cin >> ws;
        getline(cin, aluno);

        int idMonitor;
        cin >> idMonitor;

        vector<int> q(9);
        for (int k = 0; k < 9; k++) cin >> q[k];

        int N;
        cin >> N;

        int pontos = 0;
        for (int j = 0; j < 9; j++) pontos += q[j];

        int idx = N - 1;
        if (idx >= 0 && idx < 3) {
            int q3 = q[idx + 6];
            if (q3 == 1) pontos += 1;
        }

        cout << aluno << "\n";
        cout << monitorName[idMonitor] << "\n";
        cout << pontos << "\n";
    }

    return 0;
}