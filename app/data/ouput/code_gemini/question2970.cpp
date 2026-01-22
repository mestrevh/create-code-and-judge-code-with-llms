/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <sstream>

unsigned long long calcula_fatorial(int n) {
    unsigned long long resultado = 1;
    for (int i = 2; i <= n; ++i) {
        resultado *= i;
    }
    return resultado;
}

std::string converte_para_base_b(unsigned long long n, int b) {
    if (n == 0) {
        return "0";
    }
    std::string resultado = "";
    const char digitos[] = "0123456789ABCDEF";
    while (n > 0) {
        resultado += digitos[n % b];
        n /= b;
    }
    std::reverse(resultado.begin(), resultado.end());
    return resultado;
}

int conta_zeros_na_string(const std::string& s) {
    int contagem = 0;
    for (char c : s) {
        if (c == '0') {
            contagem++;
        }
    }
    return contagem;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string linha;
    while (std::getline(std::cin, linha)) {
        if (linha.empty()) {
            continue;
        }

        std::stringstream ss(linha);
        std::string primeiro_token;
        ss >> primeiro_token;

        std::string token_maiusculo = primeiro_token;
        for (char &c : token_maiusculo) {
            c = std::toupper(static_cast<unsigned char>(c));
        }

        if (token_maiusculo == "FIM") {
            break;
        }

        int n;
        int b;

        try {
            n = std::stoi(primeiro_token);
        } catch (...) {
            continue;
        }
        
        if (!(ss >> b)) {
            continue;
        }

        if (n < 0) {
            std::cout << "Numero negativo" << std::endl;
            continue;
        }

        if (b <= 1) {
            std::cout << "Base invalida" << std::endl;
            continue;
        }

        unsigned long long fatorial_n = calcula_fatorial(n);
        std::string str_base_b = converte_para_base_b(fatorial_n, b);
        int zeros = conta_zeros_na_string(str_base_b);
        size_t digitos = str_base_b.length();

        std::cout << fatorial_n << " " << str_base_b << " " << zeros << " " << digitos << std::endl;
    }

    return 0;
}
