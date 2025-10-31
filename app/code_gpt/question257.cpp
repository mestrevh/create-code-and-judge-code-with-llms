/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::string s;
    std::getline(std::cin, s);
    int count = 0;
    
    for (char c : s) {
        if (isdigit(c)) {
            count++;
        }
    }
    
    std::cout << count << std::endl;
    return 0;
}
