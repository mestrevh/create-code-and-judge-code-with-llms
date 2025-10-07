/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    char letter;
    std::string phrase;
    std::getline(std::cin, std::string{}); 
    std::cin >> letter;
    std::getline(std::cin, phrase);
    int count = 0;
    for (char c : phrase) {
        if (c == letter) {
            count++;
        }
    }
    std::cout << count << std::endl;
    return 0;
}

