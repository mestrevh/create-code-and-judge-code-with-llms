/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    int rows, cols;
    std::cin >> rows >> cols;
    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols));
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cin >> matrix[i][j];
        }
    }
    
    int sum = 0;
    std::vector<bool> haunted(cols, false);
    
    for (int i = 0; i < cols; ++i) {
        if (matrix[0][i] == 0) haunted[i] = true; // Mark haunted rooms
    }
    
    for (int i = 1; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (haunted[j]) continue; // Skip haunted rooms
            if (matrix[i][j] == 0) haunted[j] = true; // Mark new haunted rooms
            sum += matrix[i][j]; // Add to sum
        }
    }
    
    std::cout << sum << std::endl;
    return 0;
}
