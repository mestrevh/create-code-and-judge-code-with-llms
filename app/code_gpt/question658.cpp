/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    while (cin >> N >> M, N || M) {
        vector<vector<int>> matrix(N, vector<int>(M));
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                cin >> matrix[i][j];

        int maxSize = 0;
        for (int top = 0; top < N; ++top) {
            for (int left = 0; left < M; ++left) {
                for (int bottom = top; bottom < N; ++bottom) {
                    for (int right = left; right < M; ++right) {
                        vector<int> linear;
                        for (int i = top; i <= bottom; ++i)
                            for (int j = left; j <= right; ++j)
                                linear.push_back(matrix[i][j]);

                        int size = linear.size();
                        if (size < 2) {
                            maxSize = max(maxSize, size);
                            continue;
                        }

                        bool isIncreasing = true;
                        for (int k = 1; k < size; ++k) {
                            if (linear[k] <= linear[k - 1]) {
                                isIncreasing = false;
                                break;
                            }
                        }
                        if (isIncreasing) {
                            maxSize = max(maxSize, size);
                        }
                    }
                }
            }
        }
        cout << maxSize << endl;
    }
    return 0;
}
