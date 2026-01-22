/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    int n1, n2;
    std::string nome;

    std::cin >> n;
    std::vector<std::string> participantes_carro(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> participantes_carro[i];
    }

    std::cin >> m;
    std::vector<std::string> participantes_moto(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> participantes_moto[i];
    }

    std::cin >> n1 >> n2;

    std::sort(participantes_carro.begin(), participantes_carro.end());
    std::sort(participantes_moto.begin(), participantes_moto.end());

    std::string vencedor_carro = participantes_carro[n1 - 1];
    std::string vencedor_moto = participantes_moto[n2 - 1];

    if (vencedor_carro == vencedor_moto) {
        std::cout << "Quem ganhou tudo hoje foi " << vencedor_carro << std::endl;
    } else {
        std::cout << "Quem ganhou o carro foi: " << vencedor_carro << std::endl;
        std::cout << "Quem ganhou a moto foi: " << vencedor_moto << std::endl;
    }

    return 0;
}
