/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <sstream>
#include <vector>

int main() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    int num, max_num = 0;
    
    while (iss >> num) {
        if (num == 0) break;
        if (num > max_num) max_num = num;
    }
    
    std::cout << max_num << std::endl;
    return 0;
}
