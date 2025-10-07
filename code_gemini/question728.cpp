/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <algorithm>

double velkmh(double v0, double a, double t) {
    double v_ms = v0 + a * t;
    return 3.6 * v_ms;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double v0_1, a_1, t_1;
    double v0_2, a_2, t_2;
    double v0_3, a_3, t_3;

    std::cin >> v0_1 >> a_1 >> t_1;
    std::cin >> v0_2 >> a_2 >> t_2;
    std::cin >> v0_3 >> a_3 >> t_3;

    double vel1 = velkmh(v0_1, a_1, t_1);
    double vel2 = velkmh(v0_2, a_2, t_2);
    double vel3 = velkmh(v0_3, a_3, t_3);

    double min_vel = std::min(vel1, std::min(vel2, vel3));

    std::cout << std::fixed << std::setprecision(1) << min_vel << std::endl;

    return 0;
}
