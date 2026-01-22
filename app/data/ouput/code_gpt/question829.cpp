/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

int main() {
    std::vector<char> chars(5);
    for (int i = 0; i < 5; ++i) {
        std::cin >> chars[i];
    }
    
    std::sort(chars.begin(), chars.end());
    std::set<char> uniqueChars(chars.begin(), chars.end());

    if (uniqueChars.size() < 5) {
        std::cout << "nao" << std::endl;
        return 0;
    }

    for (int i = 1; i < 5; ++i) {
        if (chars[i] != chars[i - 1] + 1) {
            std::cout << "nao" << std::endl;
            return 0;
        }
    }
    
    std::cout << "sim" << std::endl;
    return 0;
}
