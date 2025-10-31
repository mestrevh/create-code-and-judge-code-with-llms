/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string compressBitmap(const vector<vector<int>>& bitmap, int x, int y, int L, int C) {
    bool allOnes = true, allZeros = true;
    for (int i = x; i < x + L; ++i) {
        for (int j = y; j < y + C; ++j) {
            if (bitmap[i][j] == 1) allZeros = false;
            if (bitmap[i][j] == 0) allOnes = false;
        }
    }
    if (allOnes) return "1";
    if (allZeros) return "0";
    
    string result = "D";
    int halfL = (L + 1) / 2, halfC = (C + 1) / 2;
    result += compressBitmap(bitmap, x, y, halfL, halfC);               // upper left
    result += compressBitmap(bitmap, x, y + halfC, halfL, C - halfC);  // upper right
    result += compressBitmap(bitmap, x + halfL, y, L - halfL, halfC);  // lower left
    result += compressBitmap(bitmap, x + halfL, y + halfC, L - halfL, C - halfC); // lower right
    return result;
}

void formatOutput(const string& str) {
    for (size_t i = 0; i < str.length(); i += 50) {
        cout << str.substr(i, 50) << endl;
    }
}

int main() {
    int n;
    cin >> n;
    
    while (n--) {
        int L, C;
        cin >> L >> C;
        vector<vector<int>> bitmap(L, vector<int>(C));
        
        for (int i = 0; i < L; ++i) {
            for (int j = 0; j < C; ++j) {
                char ch;
                cin >> ch;
                bitmap[i][j] = ch - '0';
            }
        }
        
        string compressed = compressBitmap(bitmap, 0, 0, L, C);
        formatOutput(compressed);
    }
    
    return 0;
}
