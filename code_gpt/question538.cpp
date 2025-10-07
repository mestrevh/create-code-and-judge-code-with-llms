/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxSumSubrectangle(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    int maxSum = INT_MIN;

    for (int left = 0; left < n; ++left) {
        vector<int> temp(n, 0);
        for (int right = left; right < n; ++right) {
            for (int i = 0; i < n; ++i) {
                temp[i] += matrix[i][right];
            }

            int currentMax = INT_MIN, currentSum = 0;
            for (int i = 0; i < n; ++i) {
                currentSum = max(temp[i], currentSum + temp[i]);
                currentMax = max(currentMax, currentSum);
            }

            maxSum = max(maxSum, currentMax);
        }
    }

    return maxSum;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    cout << maxSumSubrectangle(matrix) << endl;
    return 0;
}
