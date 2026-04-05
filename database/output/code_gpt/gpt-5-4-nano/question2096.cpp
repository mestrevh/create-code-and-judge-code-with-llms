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

    const int R = 9, C = 9;
    vector<vector<int>> A(R, vector<int>(C)), B(R, vector<int>(C));

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            cin >> A[i][j];

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            cin >> B[i][j];

    int aCount = 0, bCount = 0;
    for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) {
        if (A[i][j] == 1) aCount++;
        if (B[i][j] == 1) bCount++;
    }

    for (int t = 0; t < N; t++) {
        string s;
        cin >> s;
        if (s.size() < 2) continue;

        int row = s[0] - 'A';
        int col = stoi(s.substr(1)) - 1;

        bool isA = (t % 2 == 0);
        vector<vector<int>> &me = isA ? A : B;
        vector<vector<int>> &other = isA ? B : A;

        int &cur = me[row][col];
        if (cur == 0) continue;

        cur = 0;
        int &hit = other[row][col];
        if (hit == 1) {
            hit = 0;
            if (isA) bCount--;
            else aCount--;
        }

        if (isA) aCount--;
        else bCount--;
    }

    if (aCount > bCount) cout << "O jogador A venceu";
    else if (bCount > aCount) cout << "O jogador B venceu";
    else cout << "Empate";

    return 0;
}