/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <cctype>

bool is_valid_plate(const std::string& plate) {
    if (plate.size() != 7) return false;
    int letter_count = 0, number_count = 0;
    for (char c : plate) {
        if (std::isdigit(c)) number_count++;
        else if (std::isupper(c)) letter_count++;
        else return false;
    }
    return letter_count == 3 && number_count == 4;
}

int main() {
    int N;
    std::cin >> N;
    std::cin.ignore();
    
    std::vector<std::string> correct_plates;
    std::vector<std::string> incorrect_plates;
    
    for (int i = 0; i < N; i++) {
        std::string plate;
        std::getline(std::cin, plate);
        
        if (is_valid_plate(plate)) {
            correct_plates.push_back(plate);
        } else {
            incorrect_plates.push_back(plate);
        }
    }
    
    std::cout << correct_plates.size() << " placas:\n";
    for (const auto& plate : correct_plates) {
        std::cout << plate << "\n";
    }
    
    std::cout << incorrect_plates.size() << " erros:\n";
    for (const auto& plate : incorrect_plates) {
        std::cout << plate << "\n";
    }

    return 0;
}
