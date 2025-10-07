/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<std::string> gerundio;
    std::vector<std::string> participio;
    std::vector<std::string> infinitivo;
    std::vector<std::string> outras;
    
    std::string palavra;
    int word_count = 0;

    while (std::cin >> palavra && palavra != "fim") {
        word_count++;
        
        std::string lower_palavra = palavra;
        std::transform(lower_palavra.begin(), lower_palavra.end(), lower_palavra.begin(),
                   [](unsigned char c){ return std::tolower(c); });
        
        if (lower_palavra.length() >= 4 && 
           (lower_palavra.substr(lower_palavra.length() - 4) == "ando" || 
            lower_palavra.substr(lower_palavra.length() - 4) == "endo" || 
            lower_palavra.substr(lower_palavra.length() - 4) == "indo")) {
            gerundio.push_back(lower_palavra);
        }
        else if (lower_palavra.length() >= 3 && 
                (lower_palavra.substr(lower_palavra.length() - 3) == "ado" || 
                 lower_palavra.substr(lower_palavra.length() - 3) == "ido")) {
            participio.push_back(lower_palavra);
        }
        else if (lower_palavra.length() >= 2 && 
                (lower_palavra.substr(lower_palavra.length() - 2) == "ar" || 
                 lower_palavra.substr(lower_palavra.length() - 2) == "er" || 
                 lower_palavra.substr(lower_palavra.length() - 2) == "ir")) {
            infinitivo.push_back(lower_palavra);
        }
        else {
            outras.push_back(lower_palavra);
        }
    }

    if (word_count == 0) {
        std::cout << "Programa finalizado, você digitou apenas a palavra *fim*, desejando encerrar o programa.\n";
        return 0;
    }

    if (!gerundio.empty()) {
        std::cout << "As palavras que você digitou no gerúndio foram as seguintes: ";
        for (size_t i = 0; i < gerundio.size(); ++i) {
            std::cout << gerundio[i] << (i == gerundio.size() - 1 ? "" : ", ");
        }
        std::cout << ".\n";
    } else {
        std::cout << "Você não digitou nenhuma palavra no gerúndio!\n";
    }

    if (!participio.empty()) {
        std::cout << "As palavras que você digitou estão no particípio: ";
        for (size_t i = 0; i < participio.size(); ++i) {
            std::cout << participio[i] << (i == participio.size() - 1 ? "" : ", ");
        }
        std::cout << ".\n";
    } else {
        std::cout << "Você não digitou nenhuma palavra no particípio!\n";
    }

    if (!infinitivo.empty()) {
        std::cout << "As palavras que você digitou no infinitivo são: ";
        for (size_t i = 0; i < infinitivo.size(); ++i) {
            std::cout << infinitivo[i] << (i == infinitivo.size() - 1 ? "" : ", ");
        }
        std::cout << ".\n";
    } else {
        std::cout << "Você não digitou nenhuma palavra no infinitivo!\n";
    }

    if (!outras.empty()) {
        std::cout << "As palavras que você digitou que não estão no gerúndio, particípio ou infinitivo e/são: ";
        for (size_t i = 0; i < outras.size(); ++i) {
            std::cout << outras[i] << (i == outras.size() - 1 ? "" : ", ");
        }
        std::cout << ".\n";
    } else {
        std::cout << "As palavras que você digitou estão enquadradas nas classes acima.\n";
    }

    return 0;
}
