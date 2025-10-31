/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty()) return 0;
    int maxArea = 0, m = matrix.size(), n = matrix[0].size();
    vector<int> heights(n, 0);
    
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            heights[j] = (matrix[i][j] == '1') ? heights[j] + 1 : 0;
        }
        
        vector<int> left(n), right(n, n);
        int currentLeft = 0, currentRight = n;
        
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == '1') {
                left[j] = max(currentLeft, left[j]);
            } else {
                currentLeft = j + 1;
                left[j] = 0;
            }
        }

        for (int j = n - 1; j >= 0; --j) {
            if (matrix[i][j] == '1') {
                right[j] = min(currentRight, right[j]);
            } else {
                currentRight = j;
                right[j] = n;
            }
        }

        for (int j = 0; j < n; ++j) {
            maxArea = max(maxArea, (right[j] - left[j]) * heights[j]);
        }
    }
    return maxArea;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    cin.ignore(); // Ignoring the first blank line

    while (t--) {
        vector<vector<char>> matrix;
        string line;

        while (getline(cin, line) && !line.empty()) {
            matrix.push_back(vector<char>(line.begin(), line.end()));
        }

        cout << maximalRectangle(matrix) << endl;
        if (t) cout << endl; // Blank line between test cases
    }
    return 0;
}
