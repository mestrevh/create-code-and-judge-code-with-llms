/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> board(8);
    for (int i = 0; i < 8; i++) {
        string line;
        if (!getline(cin, line)) return 0;
        while(line.size() == 0) {
            if(!getline(cin, line)) return 0;
        }
        vector<string> tokens;
        string cur;
        for (char c : line) {
            if (c == ' ') {
                if (!cur.empty()) { tokens.push_back(cur); cur.clear(); }
            } else cur.push_back(c);
        }
        if (!cur.empty()) tokens.push_back(cur);
        if ((int)tokens.size() == 1 && tokens[0].size() == 0) { i--; continue; }

        if ((int)tokens.size() == 8) {
            for (int j = 0; j < 8; j++) board[i] = ""; // reset
            for (int j = 0; j < 8; j++) {
                if (board[i].empty()) board[i].clear();
            }
            string row;
            row.reserve(16);
            for (int j = 0; j < 8; j++) {
                if (tokens[j] == "-" || tokens[j] == "*" || tokens[j] == "%" || tokens[j] == "#") {
                    if (tokens[j] == "-") row += '-';
                    else if (tokens[j] == "*") row += '*';
                    else if (tokens[j] == "%") row += '%';
                    else row += '#';
                } else {
                    row += tokens[j][0];
                }
            }
            board[i] = row;
        } else {
            vector<string> toks;
            for (char c : line) {
                if (c == ' ') continue;
                if (c == '\r' || c == '\n' || c == '\t') continue;
            }
            vector<char> cells;
            cells.reserve(8);
            string accum;
            for (char c : line) {
                if (c==' ') {
                    if(!accum.empty()){
                        cells.push_back(accum[0]);
                        accum.clear();
                    }
                } else accum.push_back(c);
            }
            if(!accum.empty()) cells.push_back(accum[0]);
            if ((int)cells.size() == 8) {
                string row;
                for (char ch: cells) row.push_back(ch);
                board[i]=row;
            } else {
                i--;
                continue;
            }
        }
    }

    auto findPiece = [&]() {
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                if (board[i][j] == '#') return pair<int,int>(i,j);
        return make_pair(-1,-1);
    };

    int N;
    cin >> N;
    vector<char> cmds(N);
    for (int i = 0; i < N; i++) cin >> cmds[i];

    int capturedCount = 0;
    bool didSopro = false;
    vector<pair<pair<int,int>, pair<int,int>>> capturesDone; // unused for final

    for (int step = 0; step < N; step++) {
        auto [r, c] = findPiece();
        char cmd = cmds[step];
        int dc = (cmd == 'D') ? 1 : -1;
        int r1 = r - 1;
        int c1 = c + dc;

        bool canCapture = false;
        int capR = -1, capC = -1, landR = -1, landC = -1;
        int capCellR = r - 1;
        int capCellC = c + dc;
        int landCellR = r - 2;
        int landCellC = c + 2*dc;

        if (capCellR >= 0 && capCellR < 8 && capCellC >= 0 && capCellC < 8 &&
            landCellR >= 0 && landCellR < 8 && landCellC >= 0 && landCellC < 8) {
            if (board[capCellR][capCellC] == '%' && board[landCellR][landCellC] == '*') {
                canCapture = true;
                capR = capCellR; capC = capCellC;
                landR = landCellR; landC = landCellC;
            }
        }

        if (canCapture) {
            if (board[r1][c1] == '*') {
                didSopro = true;
                cout << "Voce deveria ter capturado a peca na casa (" << capC << "," << capR << ").\n";
            }
            if (canCapture) {
                cout << "Voce capturou uma peca na casa (" << capC << "," << capR << ") e avancou para a casa (" << landC << "," << landR << ").\n";
                board[capR][capC] = '*';
                board[r][c] = '*';
                board[landR][landC] = '#';
                capturedCount++;
            }
        } else {
            if (r1 >= 0 && r1 < 8 && c1 >= 0 && c1 < 8) {
                if (board[r1][c1] == '*') {
                    board[r][c] = '*';
                    board[r1][c1] = '#';
                    cout << "Voce avancou para a casa (" << c1 << "," << r1 << ").\n";
                } else if (board[r1][c1] == '%') {
                    int landCellR = r - 2;
                    int landCellC = c + 2*dc;
                    if (landCellR >= 0 && landCellR < 8 && landCellC >= 0 && landCellC < 8 &&
                        board[landCellR][landCellC] == '*') {
                        int badCapR = r - 1, badCapC = c + dc;
                        int badLandR = r - 2, badLandC = c + 2*dc;
                        bool invalid = false;
                        int nextCellR = badLandR - 1;
                        int nextCellC = badLandC + dc;
                        int nextLandR = badLandR - 2;
                        int nextLandC = badLandC + 2*dc;
                        if (nextCellR >= 0 && nextCellR < 8 && nextCellC >= 0 && nextCellC < 8 &&
                            nextLandR >= 0 && nextLandR < 8 && nextLandC >= 0 && nextLandC < 8) {
                            if (board[nextCellR][nextCellC] == '%' && board[nextLandR][nextLandC] == '%') {
                                invalid = true;
                            }
                        }
                        if (invalid) {
                            cout << "Voce nao pode capturar essa peca.\n";
                        } else {
                            cout << "Voce capturou uma peca na casa (" << badCapC << "," << badCapR << ") e avancou para a casa (" << badLandC << "," << badLandR << ").\n";
                            board[badCapR][badCapC] = '*';
                            board[r][c] = '*';
                            board[badLandR][badLandC] = '#';
                            capturedCount++;
                        }
                    } else {
                        cout << "Voce avancou para a casa (" << c1 << "," << r1 << ").\n";
                    }
                } else {
                    cout << "Voce avancou para a casa (" << c1 << "," << r1 << ").\n";
                }
            }
        }
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << board[i][j];
            if (j != 7) cout << ' ';
        }
        if (i != 7) cout << "\n";
    }
    cout << "\n";
    cout << "Voce capturou " << capturedCount << " pecas.\n";
    if (didSopro) cout << "Deu sopro.\n";

    return 0;
}