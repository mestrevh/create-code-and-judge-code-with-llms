/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool seg[10][7] = {
    {1, 1, 1, 0, 1, 1, 1},
    {0, 0, 1, 0, 0, 1, 0},
    {1, 0, 1, 1, 1, 0, 1},
    {1, 0, 1, 1, 0, 1, 1},
    {0, 1, 1, 1, 0, 1, 0},
    {1, 1, 0, 1, 0, 1, 1},
    {1, 1, 0, 1, 1, 1, 1},
    {1, 0, 1, 0, 0, 1, 0},
    {1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 0, 1, 1}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int s;
    string n;
    while (cin >> s >> n && (s != 0 || n != "0")) {
        int rows = 2 * s + 3;
        for (int r = 0; r < rows; ++r) {
            for (int i = 0; i < (int)n.length(); ++i) {
                int d = n[i] - '0';
                if (r == 0) {
                    cout << ' ';
                    for (int k = 0; k < s; ++k) cout << (seg[d][0] ? '-' : ' ');
                    cout << ' ';
                } else if (r > 0 && r < s + 1) {
                    cout << (seg[d][1] ? '|' : ' ');
                    for (int k = 0; k < s; ++k) cout << ' ';
                    cout << (seg[d][2] ? '|' : ' ');
                } else if (r == s + 1) {
                    cout << ' ';
                    for (int k = 0; k < s; ++k) cout << (seg[d][3] ? '-' : ' ');
                    cout << ' ';
                } else if (r > s + 1 && r < 2 * s + 2) {
                    cout << (seg[d][4] ? '|' : ' ');
                    for (int k = 0; k < s; ++k) cout << ' ';
                    cout << (seg[d][5] ? '|' : ' ');
                } else {
                    cout << ' ';
                    for (int k = 0; k < s; ++k) cout << (seg[d][6] ? '-' : ' ');
                    cout << ' ';
                }
                
                if (i < (int)n.length() - 1) {
                    cout << ' ';
                }
            }
            cout << '\n';
        }
        cout << '\n';
    }

    return 0;
}