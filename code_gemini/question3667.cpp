/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void print_list(const std::vector<std::string>& guests) {
    for (const auto& guest : guests) {
        std::cout << guest << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<std::string> marilda_guests;
    std::string name;

    while (std::getline(std::cin, name) && name != "FIM") {
        marilda_guests.push_back(name);
    }

    std::vector<std::string> brother_guests;
    while (std::getline(std::cin, name) && name != "FIM") {
        brother_guests.push_back(name);
    }

    std::sort(marilda_guests.begin(), marilda_guests.end());
    std::sort(brother_guests.begin(), brother_guests.end());

    print_list(marilda_guests);
    std::cout << std::string(50, '-') << '\n';
    print_list(brother_guests);
    std::cout << std::string(50, '-') << '\n';

    std::vector<std::string> merged_list;
    merged_list.reserve(marilda_guests.size() + brother_guests.size());
    
    auto it_marilda = marilda_guests.begin();
    auto it_brother = brother_guests.begin();

    while (it_marilda != marilda_guests.end() && it_brother != brother_guests.end()) {
        if (*it_marilda < *it_brother) {
            merged_list.push_back(*it_marilda);
            ++it_marilda;
        } else {
            merged_list.push_back(*it_brother);
            ++it_brother;
        }
    }

    while (it_marilda != marilda_guests.end()) {
        merged_list.push_back(*it_marilda);
        ++it_marilda;
    }

    while (it_brother != brother_guests.end()) {
        merged_list.push_back(*it_brother);
        ++it_brother;
    }

    print_list(merged_list);

    return 0;
}
