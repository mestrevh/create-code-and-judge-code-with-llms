/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::string s;
    int i1, f1, i2, f2;
    
    std::getline(std::cin, s);
    std::cin >> i1 >> f1 >> i2 >> f2;
    
    std::string s1 = s.substr(i1, f1 - i1 + 1);
    std::string s2 = s.substr(i2, f2 - i2 + 1);
    
    std::cout << s1 << s2 << std::endl;
    
    return 0;
}
