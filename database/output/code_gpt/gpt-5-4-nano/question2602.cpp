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

    int A[9][9], B[9][9];
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            cin >> A[i][j];

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            cin >> B[i][j];

    auto parsePos = [&](const string& s)->pair<int,int>{
        char r = s[0];
        int row = r - 'A';
        int col = (s.size() >= 2 ? s[1]-'1' : 0);
        return {row, col};
    };

    for (int k = 0; k < N; k++) {
        string s;
        cin >> s;
        auto [r,c] = parsePos(s);
        int player = (k % 2 == 0) ? 0 : 1;
        if (player == 0) {
            if (A[r][c] == 1) {
                A[r][c] = 0;
                continue;
            }
            B[r][c] = 0;
        } else {
            if (B[r][c] == 1) {
                B[r][c] = 0;
                continue;
            }
            A[r][c] = 0;
        }
    }

    int countA = 0, countB = 0;
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++) {
            countA += A[i][j];
            countB += B[i][j];
        }

    if (countA > countB) cout << "O jogador A venceu";
    else if (countB > countA) cout << "O jogador B venceu";
    else cout << "Empate";
    return 0;
}