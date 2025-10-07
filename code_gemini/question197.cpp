/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    if (n == 0) {
        return 0;
    }

    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));

    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;

    while (top <= bottom && left <= right) {
        // Traverse Right
        for (int c = left; c <= right; ++c) {
            std::cin >> matrix[top][c];
        }
        top++;

        // Traverse Down
        for (int r = top; r <= bottom; ++r) {
            std::cin >> matrix[r][right];
        }
        right--;

        // Traverse Left
        if (top <= bottom) {
            for (int c = right; c >= left; --c) {
                std::cin >> matrix[bottom][c];
            }
            bottom--;
        }

        // Traverse Up
        if (left <= right) {
            for (int r = bottom; r >= top; --r) {
                std::cin >> matrix[r][left];
            }
            left++;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << matrix[i][j] << '\n';
        }
    }

    return 0;
}
