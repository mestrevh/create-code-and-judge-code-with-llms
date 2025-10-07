/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string name;
    std::cin >> name;
    if (!name.empty()) {
        std::reverse(name.begin(), name.end());
        name[0] = toupper(name[0]);
        if (name.length() > 1) {
            name[name.length() - 1] = toupper(name[name.length() - 1]);
        }
    }
    std::cout << name << std::endl;
    return 0;
}
