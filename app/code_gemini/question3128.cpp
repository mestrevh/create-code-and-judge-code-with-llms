/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>
#include <limits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    const int NUM_PEOPLE = 5;
    std::vector<std::pair<std::string, int>> people_data;
    long long sum_of_ages = 0;
    long double product_of_ages = 1.0;

    for (int i = 0; i < NUM_PEOPLE; ++i) {
        std::string name;
        std::getline(std::cin, name);

        double temp_age;
        std::cin >> temp_age;

        int processed_age = static_cast<int>(std::fabs(temp_age));

        people_data.push_back({name, processed_age});
        
        sum_of_ages += processed_age;
        product_of_ages *= processed_age;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    for (const auto& person : people_data) {
        std::cout << "Pessoa: " << person.first << " , " << person.second << std::endl;
    }

    std::cout << sum_of_ages << std::endl;

    double arithmetic_mean = static_cast<double>(sum_of_ages) / NUM_PEOPLE;
    
    double geometric_mean = 0.0;
    if (product_of_ages >= 0) {
        geometric_mean = std::pow(product_of_ages, 1.0 / NUM_PEOPLE);
    }
    
    int truncated_geometric_mean = static_cast<int>(geometric_mean);

    std::cout << std::fixed << std::setprecision(1) << arithmetic_mean << std::endl;
    std::cout << truncated_geometric_mean << std::endl;

    return 0;
}
