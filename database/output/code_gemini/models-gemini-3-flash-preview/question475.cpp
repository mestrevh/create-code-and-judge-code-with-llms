/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <cctype>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<std::string> names(10);
    for (int i = 0; i < 10; ++i) {
        std::cin >> names[i];
    }

    char target;
    std::cin >> target;
    target = (char)std::tolower((unsigned char)target);

    for (int i = 0; i < 10; ++i) {
        bool found = false;
        for (char c : names[i]) {
            if ((char)std::tolower((unsigned char)c) == target) {
                found = true;
                break;
            }
        }
        if (found) {
            std::cout << names[i] << "\n";
        }
    }

    return 0;
}