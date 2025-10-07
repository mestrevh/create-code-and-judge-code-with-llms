/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

struct Soldier {
    std::string name;
    int height;
};

bool compareSoldiers(const Soldier& a, const Soldier& b) {
    if (a.height != b.height) {
        return a.height < b.height;
    }
    return std::tolower(a.name[0]) < std::tolower(b.name[0]);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<Soldier> soldiers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> soldiers[i].name >> soldiers[i].height;
    }

    std::sort(soldiers.begin(), soldiers.end(), compareSoldiers);

    for (int i = 0; i < n; ++i) {
        std::cout << soldiers[i].name;
        if (i < n - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}
