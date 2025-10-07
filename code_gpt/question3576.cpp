/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

char transform(char c) {
    if (c >= 'a' && c <= 'z') {
        return (c == 'z') ? 'a' : (c + 1);
    }
    return c;
}

int main() {
    int N;
    std::cin >> N;
    std::vector<std::vector<char>> matrix(N, std::vector<char>(N));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    std::vector<std::vector<char>> result(N, std::vector<char>(N));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            result[i][j] = transform(matrix[j][i]);
        }
    }

    for (const auto& row : result) {
        for (char c : row) {
            std::cout << c;
        }
        std::cout << std::endl;
    }

    return 0;
}
