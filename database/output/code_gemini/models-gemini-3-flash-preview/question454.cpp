/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

/**
 * Funcao auxiliar para converter string para letras maiusculas,
 * garantindo que a comparacao seja insensivel a caso (case-insensitive).
 */
string to_upper(string s) {
    for (auto &c : s) {
        c = (char)toupper((unsigned char)c);
    }
    return s;
}

int main() {
    // Otimizacao de I/O para competicao
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string product, flavor;
    int quantity;

    // Leitura das duas strings e do inteiro conforme o formato de entrada
    if (!(cin >> product >> flavor >> quantity)) return 0;

    // Normalizacao para facilitar a decisao
    product = to_upper(product);
    flavor = to_upper(flavor);

    double base_price = 0.0;

    if (product == "PIZZA") {
        if (flavor == "CALABRESA" || flavor == "MARGUERITA") {
            base_price = 20.60;
        } else {
            // Outros sabores de pizza
            base_price = 30.90;
        }
    } else if (product == "LASANHA") {
        if (flavor == "QUEIJO") {
            base_price = 18.00;
        } else if (flavor == "BOLONHESA") {
            base_price = 23.00;
        }
    }

    // Calculo do total: (Preco unitario + R$ 2 de taxa de entrega por item) * quantidade
    double total_value = (base_price + 2.00) * (double)quantity;

    // Formatacao de saida: valor real com duas casas decimais
    cout << fixed << setprecision(2) << total_value << endl;

    return 0;
}