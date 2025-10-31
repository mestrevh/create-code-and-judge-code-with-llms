/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int Fd, Bd, Md;
    std::cin >> Fd >> Bd >> Md;
    int Fr, Br, Mr;
    std::cin >> Fr >> Br >> Mr;
    int nao_atendidos = 0;
    if (Fr > Fd) {
        nao_atendidos += Fr - Fd;
    }
    if (Br > Bd) {
        nao_atendidos += Br - Bd;
    }
    if (Mr > Md) {
        nao_atendidos += Mr - Md;
    }
    std::cout << nao_atendidos << std::endl;
    return 0;
}
