/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double preco_ingresso = 5.0;
    int ingressos_vendidos = 120;
    double despesas_fixas = 200.0;

    for (double i = preco_ingresso; i >= 1.0; i -= 0.5) {
        double receita = i * ingressos_vendidos;
        double lucro = receita - despesas_fixas;
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "preco do ingresso: R$ " << i << " / publico esperado: " << ingressos_vendidos << " / lucro esperado: R$ " << lucro << "\n";
        
        ingressos_vendidos += 26;
    }
    
    return 0;
}
