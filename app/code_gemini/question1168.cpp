/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int v, p;
    std::cin >> v >> p;

    const double PI = 3.14;
    
    // Pool base area in cm^2
    const double pool_base_area = (500.0 * 400.0);

    // Voltorb volume in cm^3
    // Diameter = 0.5m = 50cm, Radius = 25cm
    double voltorb_radius = 25.0;
    double voltorb_volume = (4.0 / 3.0) * PI * pow(voltorb_radius, 3);

    // Pokeball volume in cm^3
    // Diameter = 7cm, Radius = 3.5cm
    double pokeball_radius = 3.5;
    double pokeball_volume = (4.0 / 3.0) * PI * pow(pokeball_radius, 3);

    double total_volume_displaced = (v * voltorb_volume) + (p * pokeball_volume);

    double height_increase_cm = total_volume_displaced / pool_base_area;

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Altura da piscina aumentou: " << height_increase_cm << " cm" << std::endl;

    return 0;
}
