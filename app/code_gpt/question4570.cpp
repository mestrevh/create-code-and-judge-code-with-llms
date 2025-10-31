/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

bool isPalindrome(std::string str) {
    std::string cleaned;
    for (char c : str) {
        if (isalpha(c)) {
            cleaned += tolower(c);
        }
    }
    int len = cleaned.length();
    for (int i = 0; i < len / 2; ++i) {
        if (cleaned[i] != cleaned[len - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int N;
    std::cin >> N;
    std::cin.ignore();
    for (int i = 1; i <= N; ++i) {
        std::string response;
        std::getline(std::cin, response);
        if (isPalindrome(response)) {
            std::cout << "Aluno " << i << ": Correto!, entendeu e trouxe um palindromo\n";
        } else {
            std::cout << "Aluno " << i << ": Incorreto!, não entendeu o que é um palindromo\n";
        }
    }
    return 0;
}
