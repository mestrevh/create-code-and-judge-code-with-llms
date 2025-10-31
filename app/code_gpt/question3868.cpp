/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isPalindrome(const string &s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        if (s[left] != s[right]) return false;
        left++; right--;
    }
    return true;
}

bool canFinish(int n, const vector<vector<char>>& floor, const string& moves) {
    int x = 0, y = 0;
    
    for (char move : moves) {
        if (move == 'C') x--;
        else if (move == 'B') x++;
        else if (move == 'D') y++;
        else if (move == 'E') y--;
        
        if (x < 0 || x >= n || y < 0 || y >= n) return false;
        if (floor[x][y] == 'x') {
            floor[x][y] = 'o';  // mark as unstable
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<vector<char>> floor(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> floor[i][j];
        }
    }

    int K;
    cin >> K;
    int count = 0;
    
    for (int i = 0; i < K; i++) {
        int T;
        string moves;
        cin >> T >> moves;
        
        if (isPalindrome(moves) || canFinish(n, floor, moves)) {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}
