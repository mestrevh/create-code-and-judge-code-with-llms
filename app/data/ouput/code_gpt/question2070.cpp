/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int calcularFuncao(int n) {
    int resultado = 0, posicao = 1;
    while (n > 0) {
        int digito = n % 10;
        n /= 10;
        resultado += (digito % 2 == 0 ? digito * 2 : digito * 3) * posicao;
        posicao++;
    }
    return resultado;
}

int main() {
    int n;
    while (std::cin >> n && n != 0) {
        std::cout << calcularFuncao(n) << std::endl;
    }
    return 0;
}
