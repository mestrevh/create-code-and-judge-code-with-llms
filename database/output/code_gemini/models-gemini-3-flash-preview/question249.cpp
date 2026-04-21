/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string s1, s2;

    if (std::getline(std::cin, s1)) {
        if (!s1.empty() && s1.back() == '\r') {
            s1.pop_back();
        }
        if (std::getline(std::cin, s2)) {
            if (!s2.empty() && s2.back() == '\r') {
                s2.pop_back();
            }
            std::cout << s1 << s2 << "\n";
        } else {
            std::cout << s1 << "\n";
        }
    }

    return 0;
}