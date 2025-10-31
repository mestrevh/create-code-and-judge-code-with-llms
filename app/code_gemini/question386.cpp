/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double total_poupado = 0.0;
    int dias_meta_cumprida = 0;
    double valor_dia_anterior = 0.0;
    double valor_dia_atual;

    for (int i = 0; i < 7; ++i) {
        std::cin >> valor_dia_atual;
        total_poupado += valor_dia_atual;

        if (i > 0) {
            if (valor_dia_atual >= valor_dia_anterior + 0.50) {
                dias_meta_cumprida++;
            }
        }
        
        valor_dia_anterior = valor_dia_atual;
    }

    std::cout << "R$ " << std::fixed << std::setprecision(2) << total_poupado << std::endl;
    std::cout << dias_meta_cumprida << std::endl;

    return 0;
}
