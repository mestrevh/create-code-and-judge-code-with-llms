/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    while (std::cin >> n && n != 0) {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::vector<std::string> guests;
        guests.reserve(n); 

        for (int i = 0; i < n; ++i) {
            std::string name;
            std::getline(std::cin, name);
            guests.push_back(name);
        }

        std::sort(guests.begin(), guests.end());

        for (const std::string& name : guests) {
            std::cout << name << '\n';
        }
    }

    return 0;
}
