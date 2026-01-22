/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

void print_list(const std::vector<std::string>& words) {
    if (words.empty()) {
        return;
    }
    for (size_t i = 0; i < words.size(); ++i) {
        std::cout << words[i];
        if (i < words.size() - 1) {
            std::cout << ", ";
        } else {
            std::cout << ".";
        }
    }
    std::cout << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<std::string> gerundio;
    std::vector<std::string> participio;
    std::vector<std::string> infinitivo;
    std::vector<std::string> outras;
    int word_count = 0;

    std::string palavra;
    while (std::cin >> palavra && palavra != "fim") {
        word_count++;
        
        std::string lower_palavra = palavra;
        std::transform(lower_palavra.begin(), lower_palavra.end(), lower_palavra.begin(),
            [](unsigned char c){ return std::tolower(c); });

        bool classified = false;
        
        if (lower_palavra.length() >= 3 && lower_palavra.substr(lower_palavra.length() - 3) == "ndo") {
            gerundio.push_back(lower_palavra);
            classified = true;
        } 
        else if (lower_palavra.length() >= 3 && (lower_palavra.substr(lower_palavra.length() - 3) == "ado" || lower_palavra.substr(lower_palavra.length() - 3) == "ido")) {
            participio.push_back(lower_palavra);
            classified = true;
        }
        else if (lower_palavra.length() >= 2 && (lower_palavra.substr(lower_palavra.length() - 2) == "ar" || lower_palavra.substr(lower_palavra.length() - 2) == "er" || lower_palavra.substr(lower_palavra.length() - 2) == "ir")) {
            infinitivo.push_back(lower_palavra);
            classified = true;
        }
        
        if (!classified) {
            outras.push_back(lower_palavra);
        }
    }

    if (word_count == 0) {
        std::cout << "Programa finalizado, você digitou apenas a palavra *fim*, desejando encerrar o programa." << std::endl;
    } else {
        if (gerundio.empty()) {
            std::cout << "Você não digitou nenhuma palavra no gerúndio!" << std::endl;
        } else {
            std::cout << "As palavras que você digitou no gerúndio foram as seguintes: ";
            print_list(gerundio);
        }

        if (participio.empty()) {
            std::cout << "Você não digitou nenhuma palavra no particípio!" << std::endl;
        } else {
            std::cout << "As palavras que você digitou estão no particípio: ";
            print_list(participio);
        }

        if (infinitivo.empty()) {
            std::cout << "Você não digitou nenhuma palavra no infinitivo!" << std::endl;
        } else {
            std::cout << "As palavras que você digitou no infinitivo são: ";
            print_list(infinitivo);
        }

        if (outras.empty()) {
            std::cout << "As palavras que você digitou estão enquadradas nas classes acima." << std::endl;
        } else {
            std::cout << "As palavras que você digitou que não estão no gerúndio, particípio ou infinitivo e/são: ";
            print_list(outras);
        }
    }

    return 0;
}
