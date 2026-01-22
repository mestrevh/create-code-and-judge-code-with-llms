/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <limits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string current_name;
    double current_height;

    std::string shortest_name;
    double shortest_height = std::numeric_limits<double>::max();

    std::string tallest_name;
    double tallest_height = 0.0;

    std::string continue_signal;

    do {
        std::cin >> current_name >> current_height;

        if (current_height < shortest_height) {
            shortest_height = current_height;
            shortest_name = current_name;
        }

        if (current_height > tallest_height) {
            tallest_height = current_height;
            tallest_name = current_name;
        }

        std::cin >> continue_signal;
        std::transform(continue_signal.begin(), continue_signal.end(), continue_signal.begin(),
                       [](unsigned char c){ return std::toupper(c); });

    } while (continue_signal != "FIM");

    std::transform(shortest_name.begin(), shortest_name.end(), shortest_name.begin(),
                   [](unsigned char c){ return std::toupper(c); });
    std::transform(tallest_name.begin(), tallest_name.end(), tallest_name.begin(),
                   [](unsigned char c){ return std::toupper(c); });

    std::cout << shortest_name << std::endl;
    std::cout << tallest_name << std::endl;

    return 0;
}
