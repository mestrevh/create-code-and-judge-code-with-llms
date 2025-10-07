/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void buildBitmap(vector<vector<char>>& bitmap, const string& s, int& index, int r, int c) {
    if (index >= s.size()) return;
    char current = s[index++];
    if (current == 'D') {
        int midR = (r + 1) / 2, midC = (c + 1) / 2;
        buildBitmap(bitmap, s, index, midR, midC); // Top Left
        buildBitmap(bitmap, s, index, midR, c - midC); // Top Right
        buildBitmap(bitmap, s, index, r - midR, midC); // Bottom Left
        buildBitmap(bitmap, s, index, r - midR, c - midC); // Bottom Right
    } else {
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                bitmap[i][j] = current;
            }
        }
    }
}

int main() {
    int n, m;
    bool firstCase = true;
    while (cin >> n >> m) {
        if (!firstCase) cout << endl;
        firstCase = false;
        
        string s;
        cin >> s;
        vector<vector<char>> bitmap(n, vector<char>(m, '0'));
        int index = 0;
        buildBitmap(bitmap, s, index, n, m);
        
        for (const auto& row : bitmap) {
            for (char c : row) {
                cout << c;
            }
            cout << endl;
        }
    }
    return 0;
}
