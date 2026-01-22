/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<std::vector<int>> matrix;
    std::string line;

    while (std::getline(std::cin, line) && line != "acabou") {
        std::stringstream ss(line);
        std::vector<int> row;
        int num;
        while (ss >> num) {
            row.push_back(num);
        }
        if (!row.empty()) {
            matrix.push_back(row);
        }
    }

    if (matrix.empty()) {
        std::cout << "Determinante diferente de zero." << std::endl;
        return 0;
    }

    int rows = matrix.size();
    int cols = matrix[0].size();

    for (size_t i = 1; i < matrix.size(); ++i) {
        if (matrix[i].size() != cols) {
            std::cout << "O determinante de uma matriz só existe para matrizes quadradas." << std::endl;
            return 0;
        }
    }

    if (rows != cols) {
        std::cout << "O determinante de uma matriz só existe para matrizes quadradas." << std::endl;
        return 0;
    }

    int n = rows;
    bool detIsZero = false;

    for (int i = 0; i < n; ++i) {
        bool rowIsZero = true;
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] != 0) {
                rowIsZero = false;
                break;
            }
        }
        if (rowIsZero) {
            detIsZero = true;
            break;
        }
    }

    if (!detIsZero) {
        for (int j = 0; j < n; ++j) {
            bool colIsZero = true;
            for (int i = 0; i < n; ++i) {
                if (matrix[i][j] != 0) {
                    colIsZero = false;
                    break;
                }
            }
            if (colIsZero) {
                detIsZero = true;
                break;
            }
        }
    }

    if (!detIsZero) {
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (matrix[i] == matrix[j]) {
                    detIsZero = true;
                    break;
                }
            }
            if (detIsZero) break;
        }
    }

    if (!detIsZero) {
        for (int j1 = 0; j1 < n; ++j1) {
            for (int j2 = j1 + 1; j2 < n; ++j2) {
                bool colsAreEqual = true;
                for (int i = 0; i < n; ++i) {
                    if (matrix[i][j1] != matrix[i][j2]) {
                        colsAreEqual = false;
                        break;
                    }
                }
                if (colsAreEqual) {
                    detIsZero = true;
                    break;
                }
            }
            if (detIsZero) break;
        }
    }

    if (detIsZero) {
        std::cout << "Determinante zero." << std::endl;
    } else {
        std::cout << "Determinante diferente de zero." << std::endl;
    }

    return 0;
}
