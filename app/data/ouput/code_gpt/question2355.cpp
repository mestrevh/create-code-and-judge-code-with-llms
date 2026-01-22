/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Place {
    std::string name;
    int distance;

    bool operator<(const Place& other) const {
        return distance < other.distance;
    }
};

int main() {
    std::vector<Place> places;
    std::string name;
    int distance;

    while (std::getline(std::cin, name) && std::cin >> distance) {
        std::cin.ignore(); // To ignore the newline after the distance
        places.push_back({name, distance});
        std::sort(places.begin(), places.end());
    }

    for (const auto& place : places) {
        std::cout << place.name << std::endl;
    }

    return 0;
}
