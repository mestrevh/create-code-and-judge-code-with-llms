/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <deque>
#include <string>

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore();
    std::deque<std::string> mensagens;

    for (int i = 0; i < n; ++i) {
        std::string mensagem;
        std::getline(std::cin, mensagem);
        mensagens.push_back(mensagem);
    }

    while (!mensagens.empty()) {
        std::cout << mensagens.front() << std::endl;
        mensagens.pop_front();
    }

    return 0;
}
