/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<char>> g(8, vector<char>(8, '-'));
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            string s;
            if (!(cin >> s)) return 0;
            if (s.empty()) { j--; continue; }
            g[i][j] = s[0];
        }
    }

    int kr = -1, kc = -1;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (g[i][j] == 'K') { kr = i; kc = j; }
        }
    }

    auto inside = [&](int r, int c) { return r >= 0 && r < 8 && c >= 0 && c < 8; };

    auto rayAttack = [&](int dr, int dc) -> bool {
        int r = kr + dr, c = kc + dc;
        while (inside(r, c)) {
            char ch = g[r][c];
            if (ch != '-') {
                char lower = (char)tolower((unsigned char)ch);
                if (lower == 't' || lower == 'q') {
                    if (dr == 0 || dc == 0) return true;
                }
                if (lower == 'b' || lower == 'q') {
                    if (abs(dr) == abs(dc)) return true;
                }
                return false;
            }
            r += dr; c += dc;
        }
        return false;
    };

    bool check = false;

    int pawnR = kr + 1;
    if (inside(pawnR, kc - 1)) if (g[pawnR][kc - 1] == 'p') check = true;
    if (!check && inside(pawnR, kc + 1)) if (g[pawnR][kc + 1] == 'p') check = true;

    int knightDr[8] = {-2,-2,-1,-1,1,1,2,2};
    int knightDc[8] = {-1,1,-2,2,-2,2,-1,1};
    for (int k = 0; k < 8 && !check; k++) {
        int r = kr + knightDr[k], c = kc + knightDc[k];
        if (inside(r,c) && g[r][c] == 'c') check = true;
    }

    if (!check) {
        if (rayAttack(1,0) || rayAttack(-1,0) || rayAttack(0,1) || rayAttack(0,-1)) check = true;
        if (!check && (rayAttack(1,1) || rayAttack(1,-1) || rayAttack(-1,1) || rayAttack(-1,-1)))) check = true;
    }

    if (!check) {
        for (int dr = -1; dr <= 1 && !check; dr++) {
            for (int dc = -1; dc <= 1 && !check; dc++) {
                if (dr == 0 && dc == 0) continue;
                int r = kr + dr, c = kc + dc;
                if (inside(r,c) && g[r][c] == 'k') check = true;
            }
        }
    }

    cout << (check ? "XEQUE" : "NAO XEQUE") << "\n";
    return 0;
}