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
        left++;
        right--;
    }
    return true;
}

pair<int, int> findPalindrome(int n, int k, vector<vector<char>> &matrix) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j + k <= n) { // Horizontal
                string substring;
                for (int l = 0; l < k; ++l) substring.push_back(matrix[i][j + l]);
                if (isPalindrome(substring)) return {i, j};
            }
            if (i + k <= n) { // Vertical
                string substring;
                for (int l = 0; l < k; ++l) substring.push_back(matrix[i + l][j]);
                if (isPalindrome(substring)) return {i, j};
            }
        }
    }
    return {-1, -1};
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<char>> matrix(n, vector<char>(n));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }
    
    auto result = findPalindrome(n, k, matrix);
    cout << "(" << result.first << ", " << result.second << ")" << endl;
    return 0;
}
