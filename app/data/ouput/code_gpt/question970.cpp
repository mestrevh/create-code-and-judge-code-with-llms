/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

void backtrack(const std::string& A, const std::string& B, int i, int j, std::vector<int>& indices) {
    if (j == B.size()) {
        for (int idx : indices) {
            std::cout << idx + 1 << " ";
        }
        std::cout << std::endl;
        return;
    }
    for (int k = i; k < A.size(); ++k) {
        if (A[k] == B[j]) {
            indices.push_back(k);
            backtrack(A, B, k + 1, j + 1, indices);
            indices.pop_back();
        }
    }
}

int main() {
    std::string A, B;
    std::getline(std::cin, A);
    std::getline(std::cin, B);
    
    std::vector<int> indices;
    bool found = false;

    backtrack(A, B, 0, 0, indices);
    
    if (indices.empty()) {
        std::cout << -1 << std::endl;
    }

    return 0;
}
