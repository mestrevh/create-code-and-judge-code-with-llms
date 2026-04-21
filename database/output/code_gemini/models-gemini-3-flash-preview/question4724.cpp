/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<std::string> frutas = {"banana", "laranja", "melancia", "morango"};
    
    if (frutas.size() >= 3) {
        std::cout << frutas[2] << std::endl;
    }

    return 0;
}