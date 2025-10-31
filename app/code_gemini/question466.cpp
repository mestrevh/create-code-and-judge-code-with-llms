/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>

void to_upper(std::string& s) {
    std::transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c){ return std::toupper(c); });
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string cityName;
    int distance;
    double price;

    std::string bestCityName = "";
    int maxDistance = -1;

    while (std::cin >> cityName) {
        std::string upperCityName = cityName;
        to_upper(upperCityName);

        if (upperCityName == "FIM") {
            break;
        }

        std::cin >> distance >> price;

        double roundTripPrice = 2 * price;

        if (roundTripPrice <= 300.0) {
            if (distance > maxDistance) {
                maxDistance = distance;
                bestCityName = upperCityName;
            }
        }
    }

    if (maxDistance == -1) {
        std::cout << "SEM DESTINO" << std::endl;
    } else {
        std::cout << bestCityName << std::endl;
    }

    return 0;
}
