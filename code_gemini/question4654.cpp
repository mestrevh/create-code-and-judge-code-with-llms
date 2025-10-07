/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string s;
    std::getline(std::cin, s);
    for (char &c : s) {
        switch (c) {
            case '0':
                c = 'o';
                break;
            case '1':
                c = 'i';
                break;
            case '3':
                c = 'e';
                break;
            case '4':
                c = 'a';
                break;
            case '5':
                c = 's';
                break;
        }
    }
    std::cout << s << std::endl;
    return 0;
}
