/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long meu_hp, meu_atk, rat_hp, rat_atk;
    std::cin >> meu_hp >> meu_atk >> rat_hp >> rat_atk;
    if ((meu_hp * meu_atk) > (rat_hp * rat_atk)) {
        std::cout << "Matei um rathound\n";
    } else {
        std::cout << "Fugi de um rathound\n";
    }
    return 0;
}
