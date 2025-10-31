/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int L, C;
    std::cin >> L >> C;

    std::vector<std::vector<std::string>> grid(L, std::vector<std::string>(C));
    long long cost = 0;

    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < C; ++j) {
            std::cin >> grid[i][j];
            if (grid[i][j] == "vermelho") {
                cost += 3;
                grid[i][j] = "amarelo";
            }
        }
    }

    int S;
    std::cin >> S;

    for (int k = 0; k < S; ++k) {
        int X, Y;
        std::cin >> X >> Y;
        int row = X - 1;
        int col = Y - 1;
        if (grid[row][col] == "amarelo") {
            grid[row][col] = "verde";
        }
    }

    long long revenue = 0;
    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < C; ++j) {
            if (grid[i][j] == "verde") {
                revenue += 4;
            }
        }
    }

    long long profit = revenue - cost;
    if (profit < 0) {
        std::cout << "prejuizo\n";
    } else {
        std::cout << profit << "\n";
    }

    return 0;
}
