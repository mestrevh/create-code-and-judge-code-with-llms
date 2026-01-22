/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

double CalculaMulta(int velocidade) {
    const int limite = 50;
    
    if (velocidade <= limite) {
        return 0.0;
    }
    
    double percentual_excedido = (double)(velocidade - limite) / limite;
    
    if (percentual_excedido <= 0.10) {
        return 230.0;
    } else if (percentual_excedido <= 0.20) {
        return 340.0;
    } else {
        return 19.28 * (velocidade - limite);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int velocidade_condutor;
    std::cin >> velocidade_condutor;
    
    double valor_multa = CalculaMulta(velocidade_condutor);
    
    std::cout << std::fixed << std::setprecision(2) << valor_multa << std::endl;
    
    return 0;
}
