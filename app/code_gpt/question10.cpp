/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    while (true) {
        int n;
        std::cin >> n;
        std::cin.ignore();
        if (n == 0) break;

        std::vector<std::string> convidados(n);
        for (int i = 0; i < n; ++i) {
            std::getline(std::cin, convidados[i]);
        }

        std::sort(convidados.begin(), convidados.end());
        
        for (const auto& nome : convidados) {
            std::cout << nome << std::endl;
        }
    }
    return 0;
}
