/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <limits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::map<int, std::string> places;
    std::string name;
    int distance;

    while (std::getline(std::cin, name)) {
        if (name.empty()) {
            continue;
        }
        std::cin >> distance;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        places[distance] = name;
    }

    for (const auto& place_pair : places) {
        std::cout << place_pair.second << '\n';
    }

    return 0;
}
