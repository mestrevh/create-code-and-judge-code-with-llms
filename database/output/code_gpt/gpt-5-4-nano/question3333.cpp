/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    char c;
    if (!(cin >> c)) return 0;
    int k = c - 'A' + 1;
    int rows = 2 * k - 1;
    
    for (int i = 0; i < rows; i++) {
        int level = i < k ? i : (rows - 1 - i);
        int spaces = k - 1 - level;
        for (int s = 0; s < spaces; s++) cout << '.';
        
        char left = char('A' + level);
        char right = left;
        for (int j = 0; j <= level; j++) cout << char('A' + j);
        for (int j = level - 1; j >= 0; j--) cout << char('A' + j);
        
        cout << "\n";
    }
    return 0;
}