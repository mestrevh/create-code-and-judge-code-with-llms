/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

void tabuada(double nota1, double nota2, double nota3) {
    double media = (nota1 + nota2 + nota3) / 3.0;
    if (media >= 6.0) {
        std::cout << "Aprovado" << std::endl;
    } else {
        std::cout << "Reprovado" << std::endl;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    double n1, n2, n3;
    std::cin >> n1 >> n2 >> n3;
    
    tabuada(n1, n2, n3);
    
    return 0;
}
