/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int d_start, m_start, a_start;
    char slash;
    std::cin >> d_start >> slash >> m_start >> slash >> a_start;

    int N;
    std::cin >> N;

    long long total_days_change = 0;
    for (int i = 0; i < N; ++i) {
        int Q;
        std::cin >> Q;
        if (Q % 2 != 0 && is_prime(Q)) {
            total_days_change -= Q;
        } else {
            total_days_change += Q;
        }
    }

    if (total_days_change < 0) {
        std::cout << "Matheusinho precisa parar AGORA ou vai de F\n";
    } else {
        std::cout << "Matheusinho tem " << total_days_change << " dias pra se recuperar\n";

        long long days_from_epoch = (long long)a_start * 360 + (long long)(m_start - 1) * 30 + (d_start - 1);
        days_from_epoch += total_days_change;

        long long final_year = days_from_epoch / 360;
        long long remaining_days_in_year = days_from_epoch % 360;
        
        long long final_month = remaining_days_in_year / 30 + 1;
        long long final_day = remaining_days_in_year % 30 + 1;

        std::cout << "Se não vai de F em " << final_day << "/" << final_month << "/" << final_year << "\n";
    }

    return 0;
}
