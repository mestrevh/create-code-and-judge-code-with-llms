/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

/**
 * Problema: Roupa alugada
 * Autor: Solução otimizada em C++ moderno
 */

int main() {
    // Otimização de I/O padrão competitiva
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string type, desc;
    
    // Leitura das duas strings (tipo de item e descrição)
    if (!(cin >> type >> desc)) return 0;

    // Normalização para maiúsculas (apenas caracteres A-Z para evitar problemas com acentuação)
    for (char &c : type) {
        if (c >= 'a' && c <= 'z') c -= 32;
    }
    for (char &c : desc) {
        if (c >= 'a' && c <= 'z') c -= 32;
    }

    double price = 0.0;

    // Lógica de decisão baseada no tipo e descrição
    // Verificamos se o tipo é "TERNO" para aplicar o desconto de 7%
    if (type == "TERNO") {
        if (desc == "SIMPLES") {
            price = 120.40;
        } else if (desc == "COMPLETO") {
            price = 150.35;
        } else if (desc == "FRAQUE") {
            price = 180.70;
        }
        // Aplicação do desconto de 7% (100% - 7% = 93%)
        price *= 0.93;
    } else {
        // Caso seja acessório ou outro tipo (tratado conforme as descrições únicas)
        if (desc == "GRAVATA") {
            price = 30.00;
        } else if (desc == "SAPATO") {
            price = 80.00;
        } else if (desc == "CINTO") {
            price = 15.00;
        }
    }

    // Saída formatada com duas casas decimais
    cout << fixed << setprecision(2) << price << endl;

    return 0;
}