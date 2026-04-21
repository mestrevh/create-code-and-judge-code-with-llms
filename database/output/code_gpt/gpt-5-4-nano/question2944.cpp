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

    const int M = 9;
    vector<vector<int>> boardA(M, vector<int>(M)), boardB(M, vector<int>(M));

    for (int i = 0; i < M; i++)
        for (int j = 0; j < M; j++)
            cin >> boardA[i][j];

    for (int i = 0; i < M; i++)
        for (int j = 0; j < M; j++)
            cin >> boardB[i][j];

    auto parsePos = [&](const string& s) -> pair<int,int> {
        char r = s[0];
        int i = r - 'A';
        int col = stoi(s.substr(1));
        int j = col - 1;
        return {i, j};
    };

    int countA = 0, countB = 0;
    for (int i = 0; i < M; i++) for (int j = 0; j < M; j++) {
        if (boardA[i][j] == 1) countA++;
        if (boardB[i][j] == 1) countB++;
    }

    for (int k = 0; k < N; k++) {
        string s;
        cin >> s;
        auto [i, j] = parsePos(s);
        if (k % 2 == 0) {
            if (boardB[i][j] == 1) {
                boardB[i][j] = 0;
                countB--;
            }
        } else {
            if (boardA[i][j] == 1) {
                boardA[i][j] = 0;
                countA--;
            }
        }
    }

    if (countA > countB) cout << "O jogador A venceu";
    else if (countB > countA) cout << "O jogador B venceu";
    else cout << "Empate";

    return 0;
}