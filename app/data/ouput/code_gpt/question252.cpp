/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::string str1, str2;
    std::getline(std::cin, str1);
    std::getline(std::cin, str2);
    
    size_t pos = 0;
    int count = 0;
    
    while ((pos = str1.find(str2, pos)) != std::string::npos) {
        count++;
        pos += str2.length();
    }
    
    std::cout << count << std::endl;
    return 0;
}
