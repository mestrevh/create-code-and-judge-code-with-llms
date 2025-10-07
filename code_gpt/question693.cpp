/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double precoA, precoC, precoP;
    int qtdeA, qtdeC, qtdeP;
    
    std::cin >> precoA >> precoC >> precoP >> qtdeA >> qtdeC >> qtdeP;
    
    double total = (precoA * qtdeA) + (precoC * qtdeC) + (precoP * qtdeP);
    
    std::cout << std::fixed << std::setprecision(2) << "Valor: R$" << total << std::endl;
    
    return 0;
}
