/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    int convidados, total_convidados = 0;
    double total_valor = 0.0;
    
    while (true) {
        std::cin >> convidados;
        if (convidados < 0) break;
        
        total_convidados += convidados;
        
        if (convidados > 15) {
            int senhas_extras = std::min(convidados - 15, 10);
            total_valor += senhas_extras * 42.0;
        }
    }
    
    std::cout << std::fixed << std::setprecision(2) << total_valor << std::endl;
    std::cout << total_convidados + 12 << std::endl;
    
    return 0;
}
