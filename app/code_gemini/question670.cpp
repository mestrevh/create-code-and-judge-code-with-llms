/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double ax, ay, bx, by, cx, cy;
    std::cin >> ax >> ay;
    std::cin >> bx >> by;
    std::cin >> cx >> cy;

    double ba_x = ax - bx;
    double ba_y = ay - by;
    double bc_x = cx - bx;
    double bc_y = cy - by;

    double dot_product = ba_x * bc_x + ba_y * bc_y;
    double mag_ba = std::sqrt(ba_x * ba_x + ba_y * ba_y);
    double mag_bc = std::sqrt(bc_x * bc_x + bc_y * bc_y);

    double cos_theta = dot_product / (mag_ba * mag_bc);

    if (cos_theta > 1.0) {
        cos_theta = 1.0;
    } else if (cos_theta < -1.0) {
        cos_theta = -1.0;
    }

    double angle_rad = std::acos(cos_theta);
    double angle_deg = angle_rad * 180.0 / acos(-1.0);

    std::cout << std::fixed << std::setprecision(2) << angle_deg << std::endl;

    return 0;
}
