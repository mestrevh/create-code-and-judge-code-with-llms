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

    std::string hs_status;
    char took_encceja;
    int encceja_score;
    std::string school_type;
    double income;

    std::cin >> hs_status >> took_encceja >> encceja_score >> school_type >> income;

    if (hs_status != "CLD" && hs_status != "CVC" && hs_status != "CSC" && hs_status != "NCC") {
        std::cout << "Informacao sobre ensino medio invalida\n";
        return 0;
    }

    bool condition1 = (hs_status == "NCC" || hs_status == "CSC") && took_encceja == 's' && encceja_score >= 400;
    bool condition2 = hs_status == "CVC" && school_type == "PUB";
    bool condition3 = (hs_status == "CLD" || hs_status == "CVC") && (school_type == "PUB" || school_type == "PCB") && income <= 1431.00;

    if (condition1 || condition2 || condition3) {
        std::cout << "Voce terah direito a isencao\n";
    } else {
        std::cout << "Infelizmente voce nao tem direito a isencao\n";
    }

    return 0;
}
