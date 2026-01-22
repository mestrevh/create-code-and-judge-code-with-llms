/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, M, n1, n2;
    std::cin >> N;
    std::vector<std::string> carro(N);
    for (int i = 0; i < N; ++i)
        std::cin >> carro[i];

    std::cin >> M;
    std::vector<std::string> moto(M);
    for (int i = 0; i < M; ++i)
        std::cin >> moto[i];

    std::sort(carro.begin(), carro.end());
    std::sort(moto.begin(), moto.end());

    std::cin >> n1 >> n2;

    std::string vencedor_carro = carro[n1 - 1];
    std::string vencedor_moto = moto[n2 - 1];

    if (vencedor_carro == vencedor_moto)
        std::cout << "Quem ganhou tudo hoje foi " << vencedor_carro << "\n";
    else {
        std::cout << "Quem ganhou o carro foi: " << vencedor_carro << "\n";
        std::cout << "Quem ganhou a moto foi: " << vencedor_moto << "\n";
    }
    
    return 0;
}
