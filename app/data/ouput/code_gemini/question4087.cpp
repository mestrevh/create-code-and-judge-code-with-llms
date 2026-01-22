/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::map<std::string, int> neighborhood_area;
    neighborhood_area["Moon Knight"] = 1;
    neighborhood_area["Daredevil"] = 1;
    neighborhood_area["Jessica Jones"] = 1;
    neighborhood_area["WandaVision"] = 2;
    neighborhood_area["Loki"] = 2;
    neighborhood_area["Hawkeye"] = 2;

    std::string neighborhood;
    std::getline(std::cin, neighborhood);

    if (neighborhood_area.find(neighborhood) == neighborhood_area.end()) {
        std::cout << "Invalid Neighborhood\n";
        return 0;
    }

    std::string day;
    int hour;
    std::cin >> day >> hour;

    int area = neighborhood_area[neighborhood];
    bool available = false;

    if (area == 1) {
        if (day == "Tuesday" && hour >= 8 && hour <= 20) {
            available = true;
        }
    } else if (area == 2) {
        if (day == "Wednesday" && hour >= 2) {
            available = true;
        }
    }

    if (available) {
        std::cout << "Water Available\n";
    } else {
        std::cout << "Water not Available\n";
    }

    return 0;
}
