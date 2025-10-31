/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::string s;
    char old_char, new_char;
    
    std::cin >> s;
    std::cin >> old_char;
    std::cin >> new_char;
    
    for (char &c : s) {
        if (c == old_char) {
            c = new_char;
        }
    }
    
    std::cout << s << std::endl;
    
    return 0;
}
