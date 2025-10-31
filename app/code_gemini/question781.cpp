/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int L, C;
    std::cin >> L >> C;

    std::vector<std::vector<int>> mat(L, std::vector<int>(C));

    int num = 1;
    int top = 0, bottom = L - 1;
    int left = 0, right = C - 1;

    while (top <= bottom && left <= right) {
        if (left <= right) {
            for (int i = top; i <= bottom; ++i) {
                mat[i][left] = num++;
            }
            left++;
        }
        
        if (left > right || top > bottom) break;

        if (right >= left) {
            for (int i = bottom; i >= top; --i) {
                mat[i][right] = num++;
            }
            right--;
        }
        
        if (left > right || top > bottom) break;

        if (bottom >= top) {
            for (int j = left; j <= right; ++j) {
                mat[bottom][j] = num++;
            }
            bottom--;
        }

        if (left > right || top > bottom) break;
        
        if (top <= bottom) {
            for (int j = left; j <= right; ++j) {
                mat[top][j] = num++;
            }
            top++;
        }
    }

    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < C; ++j) {
            std::cout << std::setw(3) << std::setfill('0') << mat[i][j];
            if (j < C - 1) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }

    return 0;
}
