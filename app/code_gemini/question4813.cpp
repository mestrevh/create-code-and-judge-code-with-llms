/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>

void calcular_amor(int dia_n, int mes_n, int ano_n, int dia_a, int mes_a, int ano_a) {
    long long soma = dia_n + mes_n + ano_n + dia_a + mes_a + ano_a;
    int porcentagem = (soma * 7) % 101;
    std::cout << "Amor: " << porcentagem << "% ";
    if (porcentagem < 20) {
        std::cout << "Pessimo dia para se apaixonar.";
    } else if (porcentagem <= 40) {
        std::cout << "Melhor manter o coracao <3 longe de perigo.";
    } else if (porcentagem <= 69) {
        std::cout << "Se o papo e as ideias baterem, esta liberado pensar em algo.";
    } else if (porcentagem <= 80) {
        std::cout << "Saia com o coracao aberto, mas lembre, nem toda troca de olhar em onibus e sinal de romance.";
    } else {
        std::cout << "Um dia deslumbrantemente lindo para amar. Ps: Cuidado com a intensidade.";
    }
    std::cout << std::endl;
}

void calcular_sorte(int dia_n, int mes_n, int ano_n, int dia_a, int mes_a, int ano_a) {
    long long soma_dias_meses = dia_n + mes_n + dia_a + mes_a;
    long long dif_anos = std::abs(ano_a - ano_n);
    int porcentagem = ((soma_dias_meses * 9) + dif_anos) % 101;
    std::cout << "Sorte: " << porcentagem << "% ";
    if (porcentagem < 30) {
        std::cout << "Nem jogue moedas pra cima hoje.";
    } else if (porcentagem <= 50) {
        std::cout << "Melhor nao arriscar.";
    } else if (porcentagem <= 79) {
        std::cout << "Por sua conta em risco.";
    } else if (porcentagem <= 90) {
        std::cout << "Hoje vale a pena arriscar.";
    } else {
        std::cout << "Nao tenha medo de virar cartas hoje.";
    }
    std::cout << " Sem tigrinho nem jogos de azar, por favor!" << std::endl;
}

void calcular_trabalho(int dia_n, int mes_n, int ano_n, int dia_a, int mes_a, int ano_a) {
    long long soma_anos = ano_n + ano_a;
    long long soma_dias_meses = dia_n + mes_n + dia_a + mes_a;
    long long resultado = soma_anos - (soma_dias_meses * 8);
    int porcentagem = (resultado % 101 + 101) % 101;
    std::cout << "Trabalho: " << porcentagem << "% ";
    if (porcentagem < 40) {
        std::cout << "Hoje nao sera um dia tao proveitoso, keep calm e faca o basico.";
    } else if (porcentagem <= 50) {
        std::cout << "Segura a emocao, nao xinga ninguem, nao esquece de beber agua.";
    } else if (porcentagem <= 69) {
        std::cout << "Um dia proveitoso com certeza, leve sua simpatia consigo.";
    } else if (porcentagem <= 84) {
        std::cout << "Boas vibracoes hoje, chances podem estar ao seu redor.";
    } else {
        std::cout << "Use do maximo de networking possível hoje, dia bom para negocios.";
    }
    std::cout << std::endl;
}

void calcular_cor(int dia_n, int mes_n, int dia_a, int mes_a) {
    long long soma_quadrados = 1LL * dia_n * dia_n + 1LL * mes_n * mes_n + 1LL * dia_a * dia_a + 1LL * mes_a * mes_a;
    int numero_cor = soma_quadrados % 11;
    std::vector<std::string> cores = {
        "Cinza.", "Vermelho.", "Laranja.", "Amarelo.", "Verde.",
        "Azul.", "Roxo.", "Marrom.", "Rosa.", "Preto.", "Branco."
    };
    std::cout << "Cor: " << cores[numero_cor] << std::endl;
}

int main() {
    int dia_n, mes_n, ano_n;
    int dia_a, mes_a, ano_a;

    scanf("%d/%d/%d %d/%d/%d", &dia_n, &mes_n, &ano_n, &dia_a, &mes_a, &ano_a);

    calcular_amor(dia_n, mes_n, ano_n, dia_a, mes_a, ano_a);
    calcular_sorte(dia_n, mes_n, ano_n, dia_a, mes_a, ano_a);
    calcular_trabalho(dia_n, mes_n, ano_n, dia_a, mes_a, ano_a);
    calcular_cor(dia_n, mes_n, dia_a, mes_a);

    return 0;
}
