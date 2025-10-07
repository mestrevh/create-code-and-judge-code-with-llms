/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int matrix[3][3];
    while (std::cin >> matrix[0][0]) {
        std::cin >> matrix[0][1] >> matrix[0][2];
        std::cin >> matrix[1][0] >> matrix[1][1] >> matrix[1][2];
        std::cin >> matrix[2][0] >> matrix[2][1] >> matrix[2][2];

        bool isUpperTriangular = (matrix[1][0] == 0 && matrix[2][0] == 0 && matrix[2][1] == 0);
        bool isLowerTriangular = (matrix[0][1] == 0 && matrix[0][2] == 0 && matrix[1][2] == 0);

        if (isUpperTriangular) {
            std::cout << "Por baixo\n";
        } else if (isLowerTriangular) {
            std::cout << "Por cima\n";
        } else {
            std::cout << "Nao pode atravessar\n";
        }
    }
    return 0;
}
