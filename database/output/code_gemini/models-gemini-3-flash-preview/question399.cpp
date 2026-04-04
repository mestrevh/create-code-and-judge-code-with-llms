/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>

using namespace std;

/**
 * CalculaHospedagem
 * Recebe o tipo de apartamento e a quantidade de diárias.
 * Retorna o valor total considerando 15% de desconto para 3 ou mais dias.
 */
double CalculaHospedagem(string tipo, int dias) {
    string t = tipo;
    // Conversão básica para lowercase para facilitar a comparação
    for (int i = 0; i < (int)t.length(); i++) {
        if (t[i] >= 'A' && t[i] <= 'Z') {
            t[i] = t[i] - 'A' + 'a';
        }
    }

    double preco_diaria = 0;
    // Identificação do tipo de apartamento baseada nas palavras-chave da tabela
    if (t.find("individual") != string::npos) {
        preco_diaria = 125.0;
    } else if (t.find("dupla") != string::npos) {
        preco_diaria = 140.0;
    } else if (t.find("tripla") != string::npos) {
        preco_diaria = 180.0;
    }

    double total = preco_diaria * (double)dias;

    // Aplicar desconto de 15% se o período for de 3 ou mais dias
    if (dias >= 3) {
        total *= 0.85;
    }

    return total;
}

int main() {
    // Otimização de I/O padrão Maratona de Programação
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string word, full_tipo = "";
    int dias = 0;
    bool found_dias = false;

    // Leitura robusta: acumula palavras do tipo de apartamento até encontrar o número de dias
    while (cin >> word) {
        bool has_digit = false;
        for (char c : word) {
            if (isdigit(static_cast<unsigned char>(c))) {
                has_digit = true;
                break;
            }
        }

        if (has_digit) {
            // Converte a palavra que contém dígitos para o inteiro de diárias
            dias = 0;
            for (char c : word) {
                if (isdigit(static_cast<unsigned char>(c))) {
                    dias = dias * 10 + (c - '0');
                }
            }
            found_dias = true;
            break;
        } else {
            // Continua construindo a string do tipo de apartamento
            if (!full_tipo.empty()) full_tipo += " ";
            full_tipo += word;
        }
    }

    if (found_dias) {
        // Saída formatada com duas casas decimais como solicitado
        cout << fixed << setprecision(2) << CalculaHospedagem(full_tipo, dias) << endl;
    }

    return 0;
}