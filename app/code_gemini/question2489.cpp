/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    std::cin.ignore(); 

    std::vector<std::string> wishlist;
    wishlist.reserve(n);
    for (int i = 0; i < n; ++i) {
        std::string item;
        std::getline(std::cin, item);
        wishlist.push_back(item);
    }

    int m;
    std::cin >> m;
    std::cin.ignore();

    std::vector<std::string> completed;
    completed.reserve(m);
    for (int i = 0; i < m; ++i) {
        std::string item;
        std::getline(std::cin, item);
        completed.push_back(item);
    }

    std::vector<std::string> remaining;
    for (const std::string& wish : wishlist) {
        bool is_completed = false;
        for (const std::string& done : completed) {
            if (wish == done) {
                is_completed = true;
                break;
            }
        }
        if (!is_completed) {
            remaining.push_back(wish);
        }
    }

    if (remaining.empty()) {
        std::cout << "Smelly Cat, Smelly Cat, what are they feeding you?\n";
    } else {
        std::cout << "Ainda falta(m) " << remaining.size() << " objetivo(s)!\n";
        for (const std::string& item : remaining) {
            std::cout << item << "\n";
        }
    }

    return 0;
}
