/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <limits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    while (N--) {
        std::string line;
        std::getline(std::cin, line);

        std::stringstream ss(line);
        std::string item;
        std::set<std::string> shopping_list;

        while (ss >> item) {
            shopping_list.insert(item);
        }

        bool first_item = true;
        for (const std::string& s : shopping_list) {
            if (!first_item) {
                std::cout << " ";
            }
            std::cout << s;
            first_item = false;
        }
        std::cout << "\n";
    }

    return 0;
}
