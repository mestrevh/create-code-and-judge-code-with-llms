/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <map>
#include <set>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int x;
    std::cin >> x;

    std::map<std::string, std::set<std::string>> suggestions;

    for (int i = 0; i < x; ++i) {
        std::string name, p1, p2, p3;
        std::cin >> name >> p1 >> p2 >> p3;
        suggestions[name].insert(p1);
        suggestions[name].insert(p2);
        suggestions[name].insert(p3);
    }

    std::string query_name, query_gift;
    while (std::cin >> query_name && query_name != "FIM") {
        std::cin >> query_gift;

        auto it = suggestions.find(query_name);
        if (it != suggestions.end() && it->second.count(query_gift)) {
            std::cout << "Uhul! Seu amigo secreto vai adorar\n";
        } else {
            std::cout << "Tente Novamente!\n";
        }
    }

    return 0;
}
