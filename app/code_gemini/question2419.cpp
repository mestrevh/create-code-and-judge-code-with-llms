/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double budget;
    std::cin >> budget;

    std::string best_name = "";
    double best_price = -1.0;
    double best_cost_benefit = -1.0;
    bool affordable_phone_found = false;

    for (int i = 0; i < 3; ++i) {
        std::string current_name;
        double current_price;
        double current_rating;
        std::cin >> current_name >> current_price >> current_rating;

        if (current_price <= budget) {
            if (!affordable_phone_found) {
                affordable_phone_found = true;
                best_name = current_name;
                best_price = current_price;
                best_cost_benefit = current_rating / current_price;
            } else {
                double current_cost_benefit = current_rating / current_price;
                if (current_cost_benefit > best_cost_benefit) {
                    best_name = current_name;
                    best_price = current_price;
                    best_cost_benefit = current_cost_benefit;
                } else if (current_cost_benefit == best_cost_benefit) {
                    if (current_price < best_price) {
                        best_name = current_name;
                        best_price = current_price;
                        best_cost_benefit = current_cost_benefit;
                    }
                }
            }
        }
    }

    if (affordable_phone_found) {
        std::cout << "Comprarei o celular " << best_name << std::endl;
    } else {
        std::cout << "O meu celular nem esta tao ruim assim" << std::endl;
    }

    return 0;
}
