/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>

int main() {
    std::string nome, maisBaixa, maisAlta;
    double altura, alturaBaixa = 1e9, alturaAlta = -1e9;

    while (true) {
        std::cin >> nome;
        if (nome == "FIM" || nome == "fim") break;
        std::cin >> altura;
        
        if (altura < alturaBaixa) {
            alturaBaixa = altura;
            maisBaixa = nome;
        }
        if (altura > alturaAlta) {
            alturaAlta = altura;
            maisAlta = nome;
        }
    }
    
    std::cout << maisBaixa << std::endl;
    std::cout << maisAlta << std::endl;

    return 0;
}
