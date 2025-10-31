/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    std::string book;
    std::vector<std::string> library;
    std::getline(std::cin, book); 
    for (int i = 0; i < n; ++i) {
        std::getline(std::cin, book);
        library.push_back(book);
    }
    std::string query_book;
    std::getline(std::cin, query_book);
    bool found = false;
    for (int i = 0; i < n; ++i) {
        if (library[i] == query_book) {
            found = true;
            break;
        }
    }
    if (found) {
        std::cout << "Sim\n";
    } else {
        std::cout << "Não\n";
    }
    return 0;
}
