/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int levi_hp;
    std::cin >> levi_hp;

    int num_titans;
    std::cin >> num_titans;

    int remaining_titans = num_titans;

    for (int i = 0; i < num_titans; ++i) {
        std::string hit_location;
        std::cin >> hit_location;

        if (levi_hp <= 0) {
            continue;
        }

        if (hit_location == "nuca") {
            remaining_titans--;
        } else if (hit_location == "cabeca") {
            levi_hp -= 30;
        } else {
            levi_hp -= 50;
        }
    }

    if (levi_hp <= 0) {
        std::cout << "Infelizmente o Levi nao sobreviveu..." << std::endl;
    } else {
        std::cout << "Levi sobreviveu com " << levi_hp << " de HP e ";
        if (remaining_titans > 0) {
            std::cout << "sobraram " << remaining_titans << " inimigos" << std::endl;
        } else {
            std::cout << "nao sobraram inimigos" << std::endl;
        }
    }

    return 0;
}
