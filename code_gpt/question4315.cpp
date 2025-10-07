/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore();
    std::vector<std::string> strings(n);
    
    for (int i = 0; i < n; ++i) {
        std::getline(std::cin, strings[i]);
    }

    std::reverse(strings.begin(), strings.end());

    for (int i = 0; i < n; ++i) {
        std::cout << strings[i];
        if (i < n - 1) std::cout << " ";
    }
    std::cout << std::endl;
    return 0;
}
