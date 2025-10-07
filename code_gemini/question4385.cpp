/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    int n, capacidade;
    std::cin >> n >> capacidade;
    while (n > 0) {
        int alunos = std::min(n, capacidade);
        std::cout << alunos << std::endl;
        n -= alunos;
    }
    return 0;
}
