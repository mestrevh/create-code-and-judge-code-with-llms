/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>

const double PI = acos(-1.0);

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    double X, Y, R;
    while (std::cin >> X >> Y >> R && (X != 0 || Y != 0 || R != 0)) {
        double P, Q, A, T;
        std::cin >> P >> Q >> A >> T;

        double cannon_x = P - X;
        double cannon_y = Q - Y;

        double alpha_rad = A * PI / 180.0;
        double theta_rad = T * PI / 180.0;

        double start_angle = alpha_rad - theta_rad / 2.0;
        double end_angle = alpha_rad + theta_rad / 2.0;

        int steps = 200000;
        double angle_step = (end_angle - start_angle) / steps;
        double total_area = 0.0;
        
        double cannon_dist_sq = cannon_x * cannon_x + cannon_y * cannon_y;

        for (int i = 0; i < steps; ++i) {
            double current_angle = start_angle + (i + 0.5) * angle_step;

            double cos_a = cos(current_angle);
            double sin_a = sin(current_angle);

            double b_half = cannon_x * cos_a + cannon_y * sin_a;
            double c = cannon_dist_sq - R * R;

            double discriminant = b_half * b_half - c;

            if (discriminant < 0) {
                continue;
            }

            double sqrt_d = sqrt(discriminant);
            double t_near = -b_half - sqrt_d;
            double t_far = -b_half + sqrt_d;
            
            double r_in = std::max(0.0, t_near);
            double r_out = std::max(0.0, t_far);
            
            total_area += 0.5 * (r_out * r_out - r_in * r_in) * angle_step;
        }

        std::cout << std::fixed << std::setprecision(1) << total_area << std::endl;
    }

    return 0;
}
