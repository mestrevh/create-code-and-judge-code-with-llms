/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

struct Shuriken {
    std::string name;
    int size;
};

bool compareShurikens(const Shuriken& a, const Shuriken& b) {
    return a.size < b.size;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<Shuriken> shurikens(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> shurikens[i].name >> shurikens[i].size;
    }

    int index;
    std::cin >> index;

    std::sort(shurikens.begin(), shurikens.end(), compareShurikens);

    std::cout << "Naruto devera usar a shuriken " << shurikens[index - 1].name << " para esta maquina." << std::endl;

    return 0;
}
