/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::string num;
    std::cin >> num;
    
    std::string inverted = std::string(num.rbegin(), num.rend());
    std::cout << inverted << std::endl;

    return 0;
}
