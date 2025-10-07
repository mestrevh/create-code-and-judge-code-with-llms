/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

struct Character {
    std::string name;
    int hp;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<Character> characters(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> characters[i].name;
        std::cin >> characters[i].hp;
    }

    int index;
    int change;

    while (std::cin >> index) {
        if (index == -1) {
            break;
        }

        std::cin >> change;

        if (index >= 0 && index < n) {
            characters[index].hp += change;
        }

        for (int i = 0; i < n; ++i) {
            std::cout << characters[i].name << " = " << characters[i].hp << std::endl;
        }
    }

    return 0;
}
