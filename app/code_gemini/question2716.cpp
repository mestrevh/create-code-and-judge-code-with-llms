/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double initial_price = 5.0;
    int initial_audience = 120;
    int fixed_costs = 200;

    double price_decrease_step = 0.5;
    int audience_increase_step = 26;

    for (int i = 0; i <= 8; ++i) {
        double current_price = initial_price - (i * price_decrease_step);
        int current_audience = initial_audience + (i * audience_increase_step);
        int profit = (current_price * current_audience) - fixed_costs;

        std::cout << "preco do ingresso: R$ " << current_price
                  << " / publico esperado: " << current_audience
                  << " / lucro esperado: R$ " << profit
                  << std::endl;
    }

    return 0;
}
