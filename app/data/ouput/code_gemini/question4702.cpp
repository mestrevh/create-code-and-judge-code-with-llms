/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

void par_ou_impar(int numero) {
    if (numero % 2 == 0) {
        std::cout << "Par" << std::endl;
    } else {
        std::cout << "Ímpar" << std::endl;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    par_ou_impar(n);
    return 0;
}
