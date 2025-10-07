/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double R, V, B, S;
    int W, D;

    std::cin >> R >> W >> D >> V >> B >> S;

    int D_now = D;
    int payment_day_of_week = (W - 1 + D_now) % 7;

    if (payment_day_of_week == 5) { // Saturday
        D_now += 2;
    } else if (payment_day_of_week == 6) { // Sunday
        D_now += 1;
    }

    long long N_now = 0;
    for (int i = 1; i <= D_now; ++i) {
        if (((W - 1 + i) % 7) < 5) {
            N_now++;
        }
    }
    
    double fine_now = B * static_cast<double>(N_now) * (static_cast<double>(N_now) + 1.0) / 2.0;
    double total_cost_now = V + fine_now;

    std::cout << std::fixed << std::setprecision(2);

    if (R >= total_cost_now) {
        double money_left_after_salary = (R - total_cost_now) + S;
        std::cout << "Nao precisa esperar e nem pedir emprestimo pague agora e ainda vai sobrar R$ " 
                  << money_left_after_salary << " quando receber o salario" << std::endl;
    } else {
        int current_payment_day_adj = (W - 1 + D_now) % 7; 
        int additional_days = (4 - current_payment_day_adj) + 7;
        int D_future = D_now + additional_days;

        long long N_future = 0;
        for (int i = 1; i <= D_future; ++i) {
            if (((W - 1 + i) % 7) < 5) {
                N_future++;
            }
        }
        
        double fine_future = B * static_cast<double>(N_future) * (static_cast<double>(N_future) + 1.0) / 2.0;
        double total_cost_future = V + fine_future;

        if ((R + S) >= total_cost_future) {
            double money_left_at_end = (R + S) - total_cost_future;
            std::cout << "Nao da pra pagar agora mas se esperar o dinheiro chegar ao inves de adquirir uma nova divida, vai sobrar R$ " 
                      << money_left_at_end << " no final de tudo" << std::endl;
        } else {
            double loan_needed = total_cost_now - R;
            std::cout << "Nao da pra pagar nem quando o salario chegar, vai ter que pedir um emprestimo de R$ " 
                      << loan_needed << std::endl;
        }
    }

    return 0;
}
