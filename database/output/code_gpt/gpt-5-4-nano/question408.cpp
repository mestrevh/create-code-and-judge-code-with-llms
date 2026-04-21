/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const vector<array<int,7>> seg = {
        array<int,7>{1,1,1,1,1,1,0}, // 0
        array<int,7>{0,1,1,0,0,0,0}, // 1
        array<int,7>{1,1,0,1,1,0,1}, // 2
        array<int,7>{1,1,1,1,0,0,1}, // 3
        array<int,7>{0,1,1,0,0,1,1}, // 4
        array<int,7>{1,0,1,1,0,1,1}, // 5
        array<int,7>{1,0,1,1,1,1,1}, // 6
        array<int,7>{1,1,1,0,0,0,0}, // 7
        array<int,7>{1,1,1,1,1,1,1}, // 8
        array<int,7>{1,1,1,1,0,1,1}  // 9
    };
    auto mapdigit = [&](int d)->array<int,7>{
        return seg[d];
    };

    string line;
    while (true) {
        long long s_ll;
        string n_str;
        if (!(cin >> s_ll >> n_str)) return 0;
        long long s = s_ll;
        if (s == 0 && (n_str == "0" || n_str == "00")) break;
        if (s == 0 && n_str == "0") break;

        if (n_str == "0") {
            n_str = "0";
        } else {
            size_t pos = 0;
            while (pos + 1 < n_str.size() && n_str[pos] == '0') pos++;
            n_str.erase(0, pos);
        }

        vector<array<int,7>> digits;
        digits.reserve(n_str.size());
        for (char c : n_str) {
            if (c >= '0' && c <= '9') digits.push_back(mapdigit(c - '0'));
        }

        int H = s + 2;
        int Wdigit = s + 2;
        int rows = 2 * s + 3;

        vector<string> out(rows, "");
        for (size_t idx = 0; idx < digits.size(); idx++) {
            array<int,7> d = digits[idx];
            int col0 = (int)idx * (Wdigit + 1);

            vector<string> canvas(rows, string(Wdigit, ' '));

            if (d[0]) for (int x = 1; x <= s; x++) canvas[0][x] = '-';
            if (d[3]) for (int x = 1; x <= s; x++) canvas[s + 1][x] = '-';
            if (d[6]) for (int x = 1; x <= s; x++) canvas[2*s+2][x] = '-';

            if (d[5]) for (int y = 1; y <= s; y++) canvas[y][0] = '|';
            if (d[1]) for (int y = 1; y <= s; y++) canvas[y][Wdigit-1] = '|';
            if (d[4]) for (int y = s + 2; y <= 2*s + 1; y++) canvas[y][0] = '|';
            if (d[2]) for (int y = s + 2; y <= 2*s + 1; y++) canvas[y][Wdigit-1] = '|';

            if (out[0].empty()) {
                out.assign(rows, string(digits.size() * (Wdigit + 1) - 1, ' '));
            }

            for (int r = 0; r < rows; r++) {
                for (int c = 0; c < Wdigit; c++) {
                    out[r][col0 + c] = canvas[r][c];
                }
                if (idx + 1 < digits.size()) {
                    out[r][col0 + Wdigit] = ' ';
                }
            }
        }

        for (int r = 0; r < rows; r++) {
            cout << out[r] << "\n";
        }
        cout << "\n";
    }

    return 0;
}