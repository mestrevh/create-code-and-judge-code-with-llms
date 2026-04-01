/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string name;
    if (std::getline(std::cin, name)) {
        if (!name.empty() && name.back() == '\r') {
            name.pop_back();
        }
        std::cout << "Olah, " << name << "!" << std::endl;
    }

    return 0;
}