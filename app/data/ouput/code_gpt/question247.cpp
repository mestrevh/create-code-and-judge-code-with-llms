/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string str;
    std::getline(std::cin, str);
    std::reverse(str.begin(), str.end());
    std::cout << str << std::endl;
    return 0;
}
