/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string name, surname;

    if (std::getline(std::cin, name)) {
        if (!name.empty() && name.back() == '\r') {
            name.pop_back();
        }
        if (std::getline(std::cin, surname)) {
            if (!surname.empty() && surname.back() == '\r') {
                surname.pop_back();
            }
            std::cout << name << " " << surname << "\n";
        }
    }

    return 0;
}