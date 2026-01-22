/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::string s1, s2;
    std::getline(std::cin, s1);
    std::getline(std::cin, s2);
    
    bool to_remove[256] = {false};
    
    for (char c : s2) {
        to_remove[static_cast<unsigned char>(c)] = true;
    }
    
    std::string result = "";
    for (char c : s1) {
        if (!to_remove[static_cast<unsigned char>(c)]) {
            result += c;
        }
    }
    
    std::cout << result << std::endl;
    
    return 0;
}
