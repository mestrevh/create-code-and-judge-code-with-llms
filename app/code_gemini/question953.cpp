/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <tuple>

struct Country {
    std::string name;
    int gold = 0;
    int silver = 0;
    int bronze = 0;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::map<std::string, Country> medal_counts;
    std::string line;

    while (std::getline(std::cin, line)) {
        if (line.empty() || line[0] == '*') {
            break;
        }

        size_t comma_pos = line.find(',');
        if (comma_pos == std::string::npos) {
            continue;
        }

        std::string country_name = line.substr(0, comma_pos);
        std::string medal_type = line.substr(comma_pos + 1);

        medal_counts[country_name].name = country_name;

        if (medal_type == "ouro") {
            medal_counts[country_name].gold++;
        } else if (medal_type == "prata") {
            medal_counts[country_name].silver++;
        } else if (medal_type == "bronze") {
            medal_counts[country_name].bronze++;
        }
    }

    std::vector<Country> countries;
    for (const auto& pair : medal_counts) {
        countries.push_back(pair.second);
    }

    std::sort(countries.begin(), countries.end(), [](const Country& a, const Country& b) {
        return std::tie(a.gold, a.silver, a.bronze) > std::tie(b.gold, b.silver, b.bronze);
    });

    int rank = 1;
    for (const auto& country : countries) {
        std::cout << rank++ << ")" << country.name
                  << " ouro:" << country.gold
                  << " prata:" << country.silver
                  << " bronze:" << country.bronze << std::endl;
    }

    return 0;
}
