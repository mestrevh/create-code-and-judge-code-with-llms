/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    vector<vector<int>> a(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) cin >> a[i][j];
    }

    long long harvested = 0;
    long long insecticide = 0;

    auto plantRow = [&](int r) {
        if (r < 0 || r >= N) return;
        for (int j = 0; j < M; j++) {
            if (a[r][j] == 0) {
                a[r][j] = 1;
                insecticide += 2;
            }
        }
        for (int j = 0; j < M; j++) {
            if (a[r][j] == 1 || a[r][j] == 2) {
                a[r][j] = 1;
                insecticide += 2;
            }
            else if (a[r][j] == 3) {
                a[r][j] = 1;
                insecticide += 2;
            }
            else if (a[r][j] == -1) {
                a[r][j] = 1;
                insecticide += 2;
            }
        }
    };

    auto plantMany = [&](int yCount, vector<int>& rows) {
        for (int idx = 0; idx < yCount; idx++) plantRow(rows[idx]);
    };

    string cmd;
    while (cin >> cmd) {
        if (cmd == "Plantar") {
            vector<int> rows;
            int x;
            while ((int)rows.size() < 1 && (cin.peek()=='\n' || cin.peek()==' ')) cin >> x;
            rows.push_back(x);
            while (cin >> x) {
                if (cin.peek() == '\n' || cin.peek() == '\r' || cin.eof()) {
                    rows.push_back(x);
                    break;
                }
                if (isalpha(cin.peek())) {
                    rows.push_back(x);
                    break;
                }
                rows.push_back(x);
                if (rows.size() > (size_t)N) {}
                if (cin.peek()=='\n' || cin.peek()=='\r') { break; }
            }
            for (int r : rows) if (r >= 1 && r <= N) plantRow(r - 1);
        } else if (cmd == "Temporada") {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    if (a[i][j] == 1) {
                        a[i][j] = 2;
                        insecticide += 2;
                    } else if (a[i][j] == 2) {
                        a[i][j] = 3;
                    }
                }
            }
        } else if (cmd == "Colher") {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    if (a[i][j] == 3) {
                        harvested++;
                        a[i][j] = 0;
                    } else if (a[i][j] == -1) {
                        a[i][j] = 0;
                    }
                }
            }
        } else if (cmd == "Ataque") {
            long long K;
            int W;
            cin >> K >> W;
            int r = (int)K;
            int c = W;
            if (r >= 0 && r < N && c >= 0 && c < M) {
                if (a[r][c] == 1 || a[r][c] == 2) a[r][c] = -1;
                else if (a[r][c] == 3) a[r][c] = -1;
            } else {
                int rr = (int)K;
                int cc = W;
                if (rr >= 1 && rr <= N && cc >= 1 && cc <= M) {
                    if (a[rr-1][cc-1] == 1 || a[rr-1][cc-1] == 2) a[rr-1][cc-1] = -1;
                    else if (a[rr-1][cc-1] == 3) a[rr-1][cc-1] = -1;
                }
            }
        } else {
            if (cmd == "0") break;
            if (cmd == "1" || cmd == "2" || cmd == "3") {
                int firstRow = stoi(cmd);
                plantRow(firstRow - 1);
            } else {
                break;
            }
        }

        if (cin.peek() == '\n' || cin.peek() == '\r') cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (cin.eof()) break;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (j) cout << ' ';
            cout << a[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
    cout << "Foram colhidos " << harvested << " morangos.\n";
    cout << "Foram utilizados " << insecticide << "ml de inseticida.";
    return 0;
}