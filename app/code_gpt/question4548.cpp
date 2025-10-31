/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

int main() {
    int pagesPrinted;
    float percentagePrinted;
    
    std::cin >> pagesPrinted >> percentagePrinted;
    
    int totalPages = std::round(pagesPrinted / (percentagePrinted / 100.0));
    int pagesLeft = totalPages - pagesPrinted;
    
    std::cout << "O documento possui " << totalPages << " paginas" << std::endl;
    std::cout << "Já foram impressas " << pagesPrinted << " paginas" << std::endl;
    std::cout << "Faltam " << pagesLeft << " paginas" << std::endl;
    
    return 0;
}
