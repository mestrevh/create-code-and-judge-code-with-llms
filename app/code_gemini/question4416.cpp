/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <iomanip>

struct Car {
    std::string name;
    double speed;
    int original_order;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int v_max;
    double distance;
    std::cin >> v_max >> distance;

    double t_a, t_b, t_c;
    std::cin >> t_a >> t_b >> t_c;

    double v_min = floor(static_cast<double>(v_max) / 2.0);

    std::vector<Car> all_cars;
    all_cars.push_back({"Kwid Laranja", distance / t_a, 0});
    all_cars.push_back({"Tesla Branco", distance / t_b, 1});
    all_cars.push_back({"Gol Bolinha",  distance / t_c, 2});
    
    std::vector<Car> valid_cars;
    for (const auto& car : all_cars) {
        if (car.speed >= v_min && car.speed <= static_cast<double>(v_max)) {
            valid_cars.push_back(car);
        }
    }

    if (valid_cars.empty()) {
        std::cout << "Infelizmente Xupenio nao podera ir ao evento mais importante do ano\n";
    } else {
        std::sort(valid_cars.begin(), valid_cars.end(), [](const Car& a, const Car& b) {
            if (a.speed != b.speed) {
                return a.speed > b.speed;
            }
            return a.original_order < b.original_order;
        });

        std::cout << std::fixed << std::setprecision(2);
        for (const auto& car : valid_cars) {
            std::cout << "Xupenio pode utilizar o carro " << car.name 
                      << ", cuja velocidade no percurso eh " << car.speed << "\n";
        }
    }

    return 0;
}
