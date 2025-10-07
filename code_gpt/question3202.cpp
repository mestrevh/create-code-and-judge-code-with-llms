/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

int main() {
    double custo, preco;
    std```cpp
#include <iostream>
#include <cmath>

int main() {
    double custo, preco;
    std::cin >> custo >> preco;

    int convites_para_cobrir_custo = std::ceil(custo / preco);
    int convites_para_lucro = std::ceil(custo * 1.23 / preco);

    std::cout << convites_para_cobrir_custo << std::endl;
    std::cout << convites_para_lucro << std::endl;

    return 0;
}
