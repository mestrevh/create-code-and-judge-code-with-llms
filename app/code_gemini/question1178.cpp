/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cstdio>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int v, p;
    std::cin >> v >> p;

    const double PI = 3.14;
    
    // Voltorb: 0.5m height/diameter -> 0.25m radius -> 25cm radius
    double voltorb_radius_cm = 25.0;
    double voltorb_volume = (4.0 / 3.0) * PI * voltorb_radius_cm * voltorb_radius_cm * voltorb_radius_cm;
    
    // Pokéball: 7cm diameter -> 3.5cm radius
    double pokeball_radius_cm = 3.5;
    double pokeball_volume = (4.0 / 3.0) * PI * pokeball_radius_cm * pokeball_radius_cm * pokeball_radius_cm;

    double total_displaced_volume = v * voltorb_volume + p * pokeball_volume;

    // Pool: 5m x 4m base -> 500cm x 400cm base
    double pool_base_area_cm2 = 500.0 * 400.0;

    double height_increase = total_displaced_volume / pool_base_area_cm2;

    printf("Altura da piscina aumentou: %.1f cm\n", height_increase);

    return 0;
}
