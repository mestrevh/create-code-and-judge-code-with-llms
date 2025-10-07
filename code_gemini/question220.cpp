/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <set>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    std::set<int> unique_registrations;
    for (int i = 0; i < n; ++i) {
        int registration;
        std::cin >> registration;
        unique_registrations.insert(registration);
    }
    std::cout << unique_registrations.size() << std::endl;
    return 0;
}
