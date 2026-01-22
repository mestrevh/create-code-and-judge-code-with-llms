/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>

std::string somaGrandesNumeros(const std::string &a, const std::string &b) {
    std::string resultado;
    int carry = 0;
    int i = a.size() - 1, j = b.size() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int somar = carry;
        if (i >= 0) somar += a[i--] - '0';
        if (j >= 0) somar += b[j--] - '0';
        resultado.push_back((somar % 10) + '0');
        carry = somar / 10;
    }

    std::reverse(resultado.begin(), resultado.end());
    return resultado;
}

int main() {
    std::string M, N;
    std::getline(std::cin, M);
    std::getline(std::cin, N);
    
    std::cout << somaGrandesNumeros(M, N) << std::endl;
    return 0;
}
