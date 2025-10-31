/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int production[12][2];
    double cost_profit[2][2];

    for (int i = 0; i < 12; ++i) {
        std::cin >> production[i][0] >> production[i][1];
    }
    for (int i = 0; i < 2; ++i) {
        std::cin >> cost_profit[i][0] >> cost_profit[i][1];
    }

    std::cout << std::fixed << std::setprecision(2);

    double annual_cost[2] = {0.0, 0.0};
    double annual_profit[2] = {0.0, 0.0};

    for (int i = 0; i < 12; ++i) {
        double monthly_cost = static_cast<double>(production[i][0]) * cost_profit[0][0];
        double monthly_profit = static_cast<double>(production[i][0]) * cost_profit[0][1];
        
        annual_cost[0] += monthly_cost;
        annual_profit[0] += monthly_profit;
        
        std::cout << "Motor[0], Mes[" << i + 1 << "], custo=[" << monthly_cost << "], lucro=[" << monthly_profit << "]\n";
    }

    for (int i = 0; i < 12; ++i) {
        double monthly_cost = static_cast<double>(production[i][1]) * cost_profit[1][0];
        double monthly_profit = static_cast<double>(production[i][1]) * cost_profit[1][1];

        annual_cost[1] += monthly_cost;
        annual_profit[1] += monthly_profit;

        std::cout << "Motor[1], Mes[" << i + 1 << "], custo=[" << monthly_cost << "], lucro=[" << monthly_profit << "]\n";
    }

    std::cout << "Motor[0], anual, custo=[" << annual_cost[0] << "], lucro=[" << annual_profit[0] << "]\n";
    std::cout << "Motor[1], anual, custo=[" << annual_cost[1] << "], lucro=[" << annual_profit[1] << "]\n";

    return 0;
}
