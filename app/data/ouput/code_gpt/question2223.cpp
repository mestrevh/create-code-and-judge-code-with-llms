/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    std::unordered_map<std::string, int> num_map = {
        {"Zero", 0}, {"Um", 1}, {"Dois", 2}, {"Tres", 3}, {"Quatro", 4},
        {"Cinco", 5}, {"Seis", 6}, {"Sete", 7}, {"Oito", 8}, {"Nove", 9}
    };
    
    std::string input;
    std::getline(std::cin, input);
    
    std::cout << num_map[input] << std::endl;
    
    return 0;
}
