/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

bool checkWin(const vector<char>& b, char p) {
    if (b[0] == p && b[1] == p && b[2] == p) return true;
    if (b[3] == p && b[4] == p && b[5] == p) return true;
    if (b[6] == p && b[7] == p && b[8] == p) return true;
    if (b[0] == p && b[3] == p && b[6] == p) return true;
    if (b[1] == p && b[4] == p && b[7] == p) return true;
    if (b[2] == p && b[5] == p && b[8] == p) return true;
    if (b[0] == p && b[4] == p && b[8] == p) return true;
    if (b[2] == p && b[4] == p && b[6] == p) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;
    while (n--) {
        vector<char> b(9);
        int x = 0, o = 0;
        for (int i = 0; i < 9; ++i) {
            cin >> b[i];
            if (b[i] == 'X') x++;
            else if (b[i] == 'O') o++;
        }

        bool wx = checkWin(b, 'X');
        bool wo = checkWin(b, 'O');

        bool illegal = false;
        if (x < o || x > o + 1) {
            illegal = true;
        } else if (wx && wo) {
            illegal = true;
        } else if (wx && x != o + 1) {
            illegal = true;
        } else if (wo && x != o) {
            illegal = true;
        }

        if (illegal) {
            cout << "ILEGAL" << endl;
        } else if (wx) {
            cout << "X_VENCEU" << endl;
        } else if (wo) {
            cout << "O_VENCEU" << endl;
        } else {
            cout << "EM_ANDAMENTO" << endl;
        }
    }

    return 0;
}