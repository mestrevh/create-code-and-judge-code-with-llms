/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    vector<int> spiral;

    for (int i = 0; i < n * n; ++i) {
        int num;
        cin >> num;
        spiral.push_back(num);
    }

    int left = 0, right = n - 1, top = 0, bottom = n - 1;
    int index = 0;

    while (left <= right && top <= bottom) {
        for (int i = left; i <= right; ++i) matrix[top][i] = spiral[index++];
        top++;
        for (int i = top; i <= bottom; ++i) matrix[i][right] = spiral[index++];
        right--;
        if (top <= bottom) {
            for (int i = right; i >= left; --i) matrix[bottom][i] = spiral[index++];
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; --i) matrix[i][left] = spiral[index++];
            left++;
        }
    }

    for (const auto& row : matrix) {
        for (const auto& value : row) {
            cout << value << endl;
        }
    }

    return 0;
}
