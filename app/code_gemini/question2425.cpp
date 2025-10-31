/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::string assento1_str, assento2_str;
    int socorrista;
    std::string opcao1_str, opcao2_str;

    std::cin >> assento1_str >> assento2_str >> socorrista >> opcao1_str >> opcao2_str;

    char r1 = assento1_str[0];
    char r2 = assento2_str[0];
    char ro1 = opcao1_str[0];
    char ro2 = opcao2_str[0];

    int dist1_aluno1 = std::abs(ro1 - r1);
    int dist1_aluno2 = std::abs(ro1 - r2);

    int melhor_dist1;
    int amigo_prox_1;

    if (dist1_aluno1 < dist1_aluno2) {
        melhor_dist1 = dist1_aluno1;
        amigo_prox_1 = 1;
    } else if (dist1_aluno2 < dist1_aluno1) {
        melhor_dist1 = dist1_aluno2;
        amigo_prox_1 = 2;
    } else {
        melhor_dist1 = dist1_aluno1;
        amigo_prox_1 = socorrista;
    }

    int dist2_aluno1 = std::abs(ro2 - r1);
    int dist2_aluno2 = std::abs(ro2 - r2);

    int melhor_dist2;
    int amigo_prox_2;

    if (dist2_aluno1 < dist2_aluno2) {
        melhor_dist2 = dist2_aluno1;
        amigo_prox_2 = 1;
    } else if (dist2_aluno2 < dist2_aluno1) {
        melhor_dist2 = dist2_aluno2;
        amigo_prox_2 = 2;
    } else {
        melhor_dist2 = dist2_aluno1;
        amigo_prox_2 = socorrista;
    }

    if (melhor_dist1 < melhor_dist2) {
        std::cout << "A opcao 1 e a mais segura\n";
    } else if (melhor_dist2 < melhor_dist1) {
        std::cout << "A opcao 2 e a mais segura\n";
    } else {
        if (amigo_prox_1 == socorrista && amigo_prox_2 != socorrista) {
            std::cout << "A opcao 1 e a mais segura\n";
        } else if (amigo_prox_2 == socorrista && amigo_prox_1 != socorrista) {
            std::cout << "A opcao 2 e a mais segura\n";
        } else {
            std::cout << "Vou fechar os olhos e decidir\n";
        }
    }

    return 0;
}
