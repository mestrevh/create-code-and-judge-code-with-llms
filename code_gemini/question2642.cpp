/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int calcular_disparos(int n) {
    if (n == 0) {
        return 0;
    }

    int x;
    std::string y;
    std::cin >> x >> y;

    int disparos_atuais = 0;
    if (y == "Conseguiu") {
        disparos_atuais = (x / 2) * 6;
    } else {
        disparos_atuais = (x / 2) * 3;
    }

    return disparos_atuais + calcular_disparos(n - 1);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    int total_disparos = calcular_disparos(n);

    std::cout << "Foram disparados: " << total_disparos << " tiros" << std::endl;

    if (total_disparos > 50) {
        std::cout << "Meus alunos estao estragando tudo! Preciso intervir!" << std::endl;
    } else {
        std::cout << "Esta tudo sobre controle, posso passar mais tempo com Raquel..." << std::endl;
    }

    return 0;
}
