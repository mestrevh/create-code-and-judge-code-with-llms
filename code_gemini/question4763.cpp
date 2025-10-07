/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int nautico_t, sport_t, santa_cruz_t, salgueiro_t;
    int t1, t2, t3, t4;
    char c1, c2, c3, c4;

    std::cin >> t1 >> c1;
    std::cin >> t2 >> c2;
    std::cin >> t3 >> c3;
    std::cin >> t4 >> c4;

    if (c1 == 'A') {
        nautico_t = t1;
        if (t1 > 24) std::cout << "Se contar direitinho ainda tá faltando uns títulos para o Timba...\n";
        else if (t1 < 24) std::cout << "Isso deve ser coisa do Sport, querem ganhar no tapetão que nem em 87!\n";
        else std::cout << "Tem algo estranho aqui...\n";
    } else if (c1 == 'B') {
        sport_t = t1;
        if (t1 > 45) std::cout << "Se antes já era grande a diferença, imagine agora...\n";
        else if (t1 < 45) std::cout << "Capaz de recorrerem no STJD e recuperarem os títulos no tapetão.\n";
        else std::cout << "Tem algo estranho aqui...\n";
    } else if (c1 == 'C') {
        salgueiro_t = t1;
        if (t1 > 1) std::cout << "Finalmente teve justiça sobre que aconteceu em 2017!\n";
        else if (t1 < 1) std::cout << "Foi roubado em 2017 e agora em 2025, existe isso não...\n";
        else std::cout << "Tem algo estranho aqui...\n";
    } else if (c1 == 'D') {
        santa_cruz_t = t1;
        if (t1 > 29) std::cout << "O Santa é gigante e esse ano vai sair da série D\n";
        else if (t1 < 29) std::cout << "É muito azar, nem com a SAF as coisas dão certo.\n";
        else std::cout << "Tem algo estranho aqui...\n";
    }

    if (c2 == 'A') {
        nautico_t = t2;
        if (t2 > 24) std::cout << "Se contar direitinho ainda tá faltando uns títulos para o Timba...\n";
        else if (t2 < 24) std::cout << "Isso deve ser coisa do Sport, querem ganhar no tapetão que nem em 87!\n";
        else std::cout << "Tem algo estranho aqui...\n";
    } else if (c2 == 'B') {
        sport_t = t2;
        if (t2 > 45) std::cout << "Se antes já era grande a diferença, imagine agora...\n";
        else if (t2 < 45) std::cout << "Capaz de recorrerem no STJD e recuperarem os títulos no tapetão.\n";
        else std::cout << "Tem algo estranho aqui...\n";
    } else if (c2 == 'C') {
        salgueiro_t = t2;
        if (t2 > 1) std::cout << "Finalmente teve justiça sobre que aconteceu em 2017!\n";
        else if (t2 < 1) std::cout << "Foi roubado em 2017 e agora em 2025, existe isso não...\n";
        else std::cout << "Tem algo estranho aqui...\n";
    } else if (c2 == 'D') {
        santa_cruz_t = t2;
        if (t2 > 29) std::cout << "O Santa é gigante e esse ano vai sair da série D\n";
        else if (t2 < 29) std::cout << "É muito azar, nem com a SAF as coisas dão certo.\n";
        else std::cout << "Tem algo estranho aqui...\n";
    }
    
    if (c3 == 'A') {
        nautico_t = t3;
        if (t3 > 24) std::cout << "Se contar direitinho ainda tá faltando uns títulos para o Timba...\n";
        else if (t3 < 24) std::cout << "Isso deve ser coisa do Sport, querem ganhar no tapetão que nem em 87!\n";
        else std::cout << "Tem algo estranho aqui...\n";
    } else if (c3 == 'B') {
        sport_t = t3;
        if (t3 > 45) std::cout << "Se antes já era grande a diferença, imagine agora...\n";
        else if (t3 < 45) std::cout << "Capaz de recorrerem no STJD e recuperarem os títulos no tapetão.\n";
        else std::cout << "Tem algo estranho aqui...\n";
    } else if (c3 == 'C') {
        salgueiro_t = t3;
        if (t3 > 1) std::cout << "Finalmente teve justiça sobre que aconteceu em 2017!\n";
        else if (t3 < 1) std::cout << "Foi roubado em 2017 e agora em 2025, existe isso não...\n";
        else std::cout << "Tem algo estranho aqui...\n";
    } else if (c3 == 'D') {
        santa_cruz_t = t3;
        if (t3 > 29) std::cout << "O Santa é gigante e esse ano vai sair da série D\n";
        else if (t3 < 29) std::cout << "É muito azar, nem com a SAF as coisas dão certo.\n";
        else std::cout << "Tem algo estranho aqui...\n";
    }
    
    if (c4 == 'A') {
        nautico_t = t4;
        if (t4 > 24) std::cout << "Se contar direitinho ainda tá faltando uns títulos para o Timba...\n";
        else if (t4 < 24) std::cout << "Isso deve ser coisa do Sport, querem ganhar no tapetão que nem em 87!\n";
        else std::cout << "Tem algo estranho aqui...\n";
    } else if (c4 == 'B') {
        sport_t = t4;
        if (t4 > 45) std::cout << "Se antes já era grande a diferença, imagine agora...\n";
        else if (t4 < 45) std::cout << "Capaz de recorrerem no STJD e recuperarem os títulos no tapetão.\n";
        else std::cout << "Tem algo estranho aqui...\n";
    } else if (c4 == 'C') {
        salgueiro_t = t4;
        if (t4 > 1) std::cout << "Finalmente teve justiça sobre que aconteceu em 2017!\n";
        else if (t4 < 1) std::cout << "Foi roubado em 2017 e agora em 2025, existe isso não...\n";
        else std::cout << "Tem algo estranho aqui...\n";
    } else if (c4 == 'D') {
        santa_cruz_t = t4;
        if (t4 > 29) std::cout << "O Santa é gigante e esse ano vai sair da série D\n";
        else if (t4 < 29) std::cout << "É muito azar, nem com a SAF as coisas dão certo.\n";
        else std::cout << "Tem algo estranho aqui...\n";
    }

    std::cout << "\n";

    int N = nautico_t;
    int B = sport_t;
    int D = santa_cruz_t;
    int C = salgueiro_t;

    if (N > B && N > D && N > C) {
        std::cout << "1º - Náutico - " << N << " - títulos\n";
        if (B > D && B > C) {
            std::cout << "2º - Sport - " << B << " - títulos\n";
            if (D > C) std::cout << "3º - Santa Cruz - " << D << " - títulos\n";
            else std::cout << "3º - Salgueiro - " << C << " - títulos\n";
        } else if (D > B && D > C) {
            std::cout << "2º - Santa Cruz - " << D << " - títulos\n";
            if (B > C) std::cout << "3º - Sport - " << B << " - títulos\n";
            else std::cout << "3º - Salgueiro - " << C << " - títulos\n";
        } else {
            std::cout << "2º - Salgueiro - " << C << " - títulos\n";
            if (B > D) std::cout << "3º - Sport - " << B << " - títulos\n";
            else std::cout << "3º - Santa Cruz - " << D << " - títulos\n";
        }
    } else if (B > N && B > D && B > C) {
        std::cout << "1º - Sport - " << B << " - títulos\n";
        if (N > D && N > C) {
            std::cout << "2º - Náutico - " << N << " - títulos\n";
            if (D > C) std::cout << "3º - Santa Cruz - " << D << " - títulos\n";
            else std::cout << "3º - Salgueiro - " << C << " - títulos\n";
        } else if (D > N && D > C) {
            std::cout << "2º - Santa Cruz - " << D << " - títulos\n";
            if (N > C) std::cout << "3º - Náutico - " << N << " - títulos\n";
            else std::cout << "3º - Salgueiro - " << C << " - títulos\n";
        } else {
            std::cout << "2º - Salgueiro - " << C << " - títulos\n";
            if (N > D) std::cout << "3º - Náutico - " << N << " - títulos\n";
            else std::cout << "3º - Santa Cruz - " << D << " - títulos\n";
        }
    } else if (D > N && D > B && D > C) {
        std::cout << "1º - Santa Cruz - " << D << " - títulos\n";
        if (N > B && N > C) {
            std::cout << "2º - Náutico - " << N << " - títulos\n";
            if (B > C) std::cout << "3º - Sport - " << B << " - títulos\n";
            else std::cout << "3º - Salgueiro - " << C << " - títulos\n";
        } else if (B > N && B > C) {
            std::cout << "2º - Sport - " << B << " - títulos\n";
            if (N > C) std::cout << "3º - Náutico - " << N << " - títulos\n";
            else std::cout << "3º - Salgueiro - " << C << " - títulos\n";
        } else {
            std::cout << "2º - Salgueiro - " << C << " - títulos\n";
            if (N > B) std::cout << "3º - Náutico - " << N << " - títulos\n";
            else std::cout << "3º - Sport - " << B << " - títulos\n";
        }
    } else {
        std::cout << "1º - Salgueiro - " << C << " - títulos\n";
        if (N > B && N > D) {
            std::cout << "2º - Náutico - " << N << " - títulos\n";
            if (B > D) std::cout << "3º - Sport - " << B << " - títulos\n";
            else std::cout << "3º - Santa Cruz - " << D << " - títulos\n";
        } else if (B > N && B > D) {
            std::cout << "2º - Sport - " << B << " - títulos\n";
            if (N > D) std::cout << "3º - Náutico - " << N << " - títulos\n";
            else std::cout << "3º - Santa Cruz - " << D << " - títulos\n";
        } else {
            std::cout << "2º - Santa Cruz - " << D << " - títulos\n";
            if (N > B) std::cout << "3º - Náutico - " << N << " - títulos\n";
            else std::cout << "3º - Sport - " << B << " - títulos\n";
        }
    }

    std::cout << "\n";

    if (N > B && N > D && N > C) {
        std::cout << "A justiça foi feita, o Timba é o maior do estado, não tem jeito!\n";
    } else if (B > N && B > D && B > C) {
        std::cout << "Deu o óbvio, o papai da cidade é o Leão!\n";
    } else if (D > N && D > B && D > C) {
        std::cout << "É o terror do Nordeste, sempre soube!\n";
    } else {
        std::cout << "Já era o maior do interior, agora é o maior do estado!\n";
    }

    return 0;
}
