/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double sweetener_for_rat_ml;
    double rat_weight_g;
    double person_weight_kg;

    std::cin >> sweetener_for_rat_ml >> rat_weight_g >> person_weight_kg;

    double lethal_dose_per_g = sweetener_for_rat_ml / rat_weight_g;
    double person_weight_g = person_weight_kg * 1000.0;
    double lethal_dose_for_person_ml = lethal_dose_per_g * person_weight_g;
    
    double sweetener_concentration = 0.001; // 1/10 of 1% = 0.001 ml per Liter based on sample case

    double lethal_soda_liters = lethal_dose_for_person_ml / sweetener_concentration;

    std::cout << std::fixed << std::setprecision(1);
    std::cout << lethal_soda_liters << "L de refrigerante poderiam levar uma pessoa de "
              << person_weight_kg << "kg a morte." << std::endl;

    return 0;
}
