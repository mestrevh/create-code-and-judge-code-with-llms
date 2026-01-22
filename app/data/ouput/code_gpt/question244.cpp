/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::string str;
    char ch;
    std::getline(std::cin, str);
    std::cin >> ch;
    
    int count = 0;
    for (char c : str) {
        if (c == ch) {
            count++;
        }
    }
    
    std::cout << count << std::endl;
    return 0;
}
