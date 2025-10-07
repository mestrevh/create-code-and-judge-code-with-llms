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
    
    std::string line;
    std::getline(std::cin, line);
    
    int count_a = 0;
    int count_e = 0;
    int count_i = 0;
    int count_o = 0;
    int count_u = 0;
    
    for (char c : line) {
        switch (c) {
            case 'a':
            case 'A':
                count_a++;
                break;
            case 'e':
            case 'E':
                count_e++;
                break;
            case 'i':
            case 'I':
                count_i++;
                break;
            case 'o':
            case 'O':
                count_o++;
                break;
            case 'u':
            case 'U':
                count_u++;
                break;
        }
    }
    
    std::cout << "a " << count_a << std::endl;
    std::cout << "e " << count_e << std::endl;
    std::cout << "i " << count_i << std::endl;
    std::cout << "o " << count_o << std::endl;
    std::cout << "u " << count_u << std::endl;
    
    return 0;
}
