/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

double calculate_Q1_calories(double R_percent, double t_joules) {
    double R_decimal = R_percent / 100.0;
    double Q1_joules = t_joules / R_decimal;
    return Q1_joules / 4.0;
}

double calculate_Q2_calories(double Q1_calories, double t_joules) {
    double t_calories = t_joules / 4.0;
    return Q1_calories - t_calories;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double R, t;

    std::cout << std::fixed << std::setprecision(2);

    while (std::cin >> R && R < 100) {
        std::cin >> t;
        double q1_cal = calculate_Q1_calories(R, t);
        double q2_cal = calculate_Q2_calories(q1_cal, t);
        
        std::cout << "Q1 = " << q1_cal << " cal\n";
        std::cout << "Q2 = " << q2_cal << " cal\n";
    }

    return 0;
}
