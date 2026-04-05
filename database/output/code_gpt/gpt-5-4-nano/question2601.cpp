/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<char>> a(3, vector<char>(3));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (!(cin >> a[i][j])) return 0;
        }
    }

    int N;
    cin >> N;

    string nomeX = "Eduardo";
    string nomeO = "Leonardo";

    auto checkWin = [&](char c) -> pair<bool, string> {
        for (int i = 0; i < 3; i++) {
            if (a[i][0] == c && a[i][1] == c && a[i][2] == c) return {true, "linha " + to_string(i + 1) + "."};
            if (a[0][i] == c && a[1][i] == c && a[2][i] == c) return {true, "coluna " + to_string(i + 1) + "."};
        }
        if (a[0][0] == c && a[1][1] == c && a[2][2] == c) return {true, "diagonal principal."};
        if (a[0][2] == c && a[1][1] == c && a[2][0] == c) return {true, "diagonal secundaria."};
        return {false, ""};
    };

    bool finished = false;

    for (int k = 0; k < N; k++) {
        char C;
        int x, y;
        cin >> C >> x >> y;

        if (finished) continue;

        string nome = (C == 'X' ? nomeX : nomeO);

        if (x < 0 || x >= 3 || y < 0 || y >= 3) {
            cout << "O Dark Souls afetou sua cabeça? Jogue dentro das demarcações do jogo.\n";
            continue;
        }
        if (a[x][y] != '*') {
            cout << "Nome não trapacei ou então vamos voltar a jogar Dark Souls.\n";
            continue;
        }

        a[x][y] = C;
        cout << nome << " efetuou sua jogada com sucesso.\n";

        auto res = checkWin(C);
        if (res.first) {
            cout << nome << " ganhou o jogo na " << res.second << "\n";
            finished = true;
        }
    }

    if (!finished) {
        bool any = false;
        for (char c : {'X', 'O'}) {
            a = a;
            auto res = checkWin(c);
            if (res.first) any = true;
        }
        if (!any) {
            cout << "Nem no jogo da velha conseguimos ganhar algo, vamos voltar para o Dark Souls.\n";
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (j) cout << ' ';
            cout << a[i][j];
        }
        cout << "\n";
    }

    return 0;
}