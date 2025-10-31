/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

int get_type(int vehicle_id) {
    while (vehicle_id >= 100) {
        vehicle_id /= 10;
    }
    return vehicle_id;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::map<int, std::multiset<int>> garages;
    const std::set<int> valid_types = {67, 65, 77, 66, 84, 83};

    std::string command;
    int value;

    while (std::cin >> command >> value) {
        if (command == "VEICULO!!!") {
            int type_code = get_type(value);
            if (valid_types.count(type_code)) {
                garages[type_code].insert(value);
            } else {
                std::cout << "VERIFICAR TIPO DE VEICULO\n";
            }
        } else if (command == "VERIFICAR") {
            int type_code = get_type(value);
            if (garages.count(type_code) && garages.at(type_code).count(value)) {
                std::cout << "EXISTE\n";
            } else {
                std::cout << "AINDA NAO\n";
            }
        } else if (command == "IMPRIMIR") {
            int type_code = value;
            if (garages.count(type_code) && !garages.at(type_code).empty()) {
                bool first = true;
                for (int vehicle_id : garages.at(type_code)) {
                    if (!first) {
                        std::cout << " ";
                    }
                    std::cout << vehicle_id;
                    first = false;
                }
                std::cout << "\n";
            } else {
                std::cout << "A GARAGEM ESTA VAZIA :(\n";
            }
        } else if (command == "VENDER") {
            int type_code = value;
            std::vector<int> sold_vehicles;

            if (garages.count(type_code)) {
                auto& garage = garages.at(type_code);
                std::set<int> unique_ids_in_garage;
                
                for(int id : garage) {
                    unique_ids_in_garage.insert(id);
                }

                for (int unique_id : unique_ids_in_garage) {
                    size_t count = garage.count(unique_id);
                    if (count > 1) {
                        for (size_t k = 0; k < count - 1; ++k) {
                            sold_vehicles.push_back(unique_id);
                            garage.erase(garage.find(unique_id));
                        }
                    }
                }
            }

            if (sold_vehicles.empty()) {
                std::cout << "NADA REPETIDO POR ENQUANTO :)\n";
            } else {
                std::sort(sold_vehicles.begin(), sold_vehicles.end());
                bool first = true;
                for (int vehicle_id : sold_vehicles) {
                    if (!first) {
                        std::cout << " ";
                    }
                    std::cout << vehicle_id;
                    first = false;
                }
                std::cout << "\n";
            }
        }
    }

    return 0;
}
