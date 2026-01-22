/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <map>

int main() {
    std::map<int, double> precos = {
        {1, 10.00}, {2, 15.00}, {3, 20.00}, {4, 30.00}
    };
    
    int codigo, quantidade;
    std::cin >> codigo >> quantidade;
    
    double total = precos[codigo] * quantidade;
    if (quantidade >= 15 || total >= 40) {
        total *= 0.85;
    }
    
    std::cout << "R$ " << std::fixed << std::setprecision(2) << total << std::endl;
    return 0;
}
