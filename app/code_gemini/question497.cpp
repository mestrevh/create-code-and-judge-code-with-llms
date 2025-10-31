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

    double sum = 0.0;
    double max_rating = -1.0;
    int max_day_index = -1;
    double current_rating;

    for (int i = 0; i < 5; ++i) {
        std::cin >> current_rating;
        sum += current_rating;
        if (current_rating > max_rating) {
            max_rating = current_rating;
            max_day_index = i;
        }
    }

    double average = sum / 5.0;
    std::cout << std::fixed << std::setprecision(2) << average << std::endl;

    std::string program_type;
    if (max_day_index == 0 || max_day_index == 3) {
        program_type = "NOVELA";
    } else if (max_day_index == 1 || max_day_index == 4) {
        program_type = "FILME";
    } else {
        program_type = "FUTEBOL";
    }

    std::cout << program_type << std::endl;

    return 0;
}
