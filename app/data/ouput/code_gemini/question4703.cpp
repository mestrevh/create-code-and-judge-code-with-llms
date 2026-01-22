/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cctype>

void contar_vogais(std::string s) {
    int a_count = 0;
    int e_count = 0;
    int i_count = 0;
    int o_count = 0;
    int u_count = 0;

    for (char ch : s) {
        char lower_ch = tolower(ch);
        switch (lower_ch) {
            case 'a':
                a_count++;
                break;
            case 'e':
                e_count++;
                break;
            case 'i':
                i_count++;
                break;
            case 'o':
                o_count++;
                break;
            case 'u':
                u_count++;
                break;
        }
    }

    std::cout << "A: " << a_count << std::endl;
    std::cout << "E: " << e_count << std::endl;
    std::cout << "I: " << i_count << std::endl;
    std::cout << "O: " << o_count << std::endl;
    std::cout << "U: " << u_count << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string palavra;
    std::cin >> palavra;
    contar_vogais(palavra);
    return 0;
}
