/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    int key;
    vector<string> decoded;
    decoded.reserve(n);

    const int SZ = 12;
    vector<vector<char>> grid(SZ, vector<char>(SZ, 'o'));

    for (int i = 0; i < n; i++) {
        cin >> key;
        string s;
        cin >> ws;
        getline(cin, s);
        while (s.size() == 0) getline(cin, s);

        string t = s;
        for (char &c : t) {
            if (c >= 'a' && c <= 'z') {
                c = char('a' + (c - 'a' - key + 26) % 26);
            } else if (c >= 'A' && c <= 'Z') {
                c = char('A' + (c - 'A' - key + 26) % 26);
            }
        }
        decoded.push_back(t);

        int x, y;
        cin >> x >> y;
        if (x >= 0 && x < SZ && y >= 0 && y < SZ) {
            grid[y][x] = 'x';
        }
    }

    for (auto &s : decoded) cout << s << "\n";
    for (int i = 0; i < SZ; i++) {
        for (int j = 0; j < SZ; j++) {
            cout << grid[i][j] << (j + 1 == SZ ? ' ' : ' ');
        }
        cout << "\n";
    }
    return 0;
}