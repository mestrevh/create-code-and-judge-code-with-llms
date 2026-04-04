/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    double num;
    if (std::cin >> num) {
        std::cout << "Digite um numero:" << std::endl;
        std::cout << "O numero informado foi: " << std::fixed << std::setprecision(1) << num << std::endl;
    }
    
    return 0;
}