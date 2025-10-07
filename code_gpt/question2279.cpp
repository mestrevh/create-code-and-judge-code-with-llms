/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

bool verificaSucessorPredecessor(int n, int x) {
    if (n == 0) return false;
    int digito = n % 10;
    if (digito == x - 1 || digito == x + 1) return true;
    return verificaSucessorPredecessor(n / 10, x);
}

int main() {
    int n, x;
    std::cin >> n >> x;
    if (verificaSucessorPredecessor(n, x)) 
        std::cout << "sim" << std::endl;
    else 
        std::cout << "nao" << std::endl;
    return 0;
}
