/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_prime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> matrix(N, vector<int>(N));
    vector<int> diagonal;

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> matrix[i][j];

    for (int i = 0; i < N; ++i) {
        sort(matrix[i].begin(), matrix[i].end());
        diagonal.push_back(matrix[i][i]);
    }

    int sum = 0;
    for (int num : diagonal) sum += num;

    if (is_prime(sum)) {
        cout << "A soma resultou em um numero primo!\n";
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (matrix[j][i] % 2 != 0) matrix[j][i] *= 2;
                cout << matrix[j][i] << " ";
            }
            cout << "\n";
        }
    } else {
        cout << "A soma resultou em um numero nao primo!\n" << sum << "\n";
        sort(diagonal.begin(), diagonal.end());
        for (int i = 0; i < N; ++i) {
            if (diagonal[i] % 2 != 0) diagonal[i] *= 2;
            for (int j = 0; j < N; ++j) {
                cout << diagonal[j] << (j == N - 1 ? "" : " ");
            }
            cout << "\n";
        }
    }

    return 0;
}
