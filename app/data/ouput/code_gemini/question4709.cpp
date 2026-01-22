/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

void amadoProfessor(int n) {
    for (int i = 1; i <= 10; ++i) {
        std::cout << n << " x " << i << " =  " << n * i << std::endl;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int numero;
    std::cin >> numero;
    amadoProfessor(numero);
    
    return 0;
}
