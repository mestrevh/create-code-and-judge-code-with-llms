/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long X;
    if (!(cin >> X)) return 0;

    const int N = 5;
    vector<vector<string>> M(N, vector<string>(N));
    int sx = -1, sy = -1;
    int tx = -1, ty = -1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            string s;
            cin >> s;
            M[i][j] = s;
            if (s == "@") { sx = i; sy = j; }
            if (s == "$") { tx = i; ty = j; }
        }
    }

    int D;
    cin >> D;
    vector<char> dirs(D);
    for (int i = 0; i < D; i++) {
        string s;
        cin >> s;
        dirs[i] = s[0];
    }

    auto markPassed = [&]() {
        if (M[sx][sy] == "@") M[sx][sy] = "*";
    };

    long long hp = X;
    bool found = false;
    bool dead = false;

    auto isWall = [&](int nx, int ny) {
        return nx < 0 || nx >= N || ny < 0 || ny >= N;
    };

    for (int i = 0; i < D; i++) {
        if (found || dead) break;

        int nx = sx, ny = sy;
        char c = dirs[i];
        if (c == 'D') ny++;
        else if (c == 'E') ny--;
        else if (c == 'C') nx--;

        if (isWall(nx, ny)) {
            cout << "Uma magic wall aqui? druid desgraçado\n";
            continue;
        }

        string cell = M[nx][ny];

        if (cell == "#") {
            cout << "Uma magic wall aqui? druid desgraçado\n";
            continue;
        }

        markPassed();

        if (cell == "$") {
            sx = nx; sy = ny;
            M[sx][sy] = "@";
            found = true;
            break;
        }

        if (cell == "*") {
            sx = nx; sy = ny;
            M[sx][sy] = "@";
            continue;
        }

        if (cell == "@") {
            sx = nx; sy = ny;
            M[sx][sy] = "@";
            continue;
        }

        bool isNum = true;
        for (char ch : cell) {
            if (!(ch == '-' || isdigit((unsigned char)ch))) { isNum = false; break; }
        }

        long long need = 0;
        if (isNum) {
            need = stoll(cell);
        } else {
            need = 0;
        }

        if (hp - need <= 0) {
            hp = 0;
            dead = true;
            cout << "Minhas HPs acabaram, esse Frost Dragon me deitou\n";
            sx = nx; sy = ny;
            M[sx][sy] = "@";
            break;
        } else {
            hp -= need;
            cout << "Minha Royal Spear deita qualquer Dragon\n";
            sx = nx; sy = ny;
            M[sx][sy] = "@";
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (j) cout << ' ';
            string cell = M[i][j];
            if (cell == "@") {
                cout << "@";
            } else if (cell == "*") {
                cout << "*";
            } else if (cell == "#") {
                cout << "#";
            } else if (cell == "$") {
                cout << "$";
            } else {
                cout << cell;
            }
        }
        cout << "\n";
    }

    if (found) cout << "Finalmente acabei a quest\n";
    else cout << "Quem foi o newba que escreveu essas coordenadas\n";

    return 0;
}