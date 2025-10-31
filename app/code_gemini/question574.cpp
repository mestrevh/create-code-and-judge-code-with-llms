/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double cotacao_dolar, aliquota_icms_percent, valor_produto_usd, valor_frete_usd;
    std::cin >> cotacao_dolar >> aliquota_icms_percent >> valor_produto_usd >> valor_frete_usd;

    double aliquota_icms_decimal = aliquota_icms_percent / 100.0;
    double valor_produto_brl = valor_produto_usd * cotacao_dolar;
    double valor_frete_brl = valor_frete_usd * cotacao_dolar;
    double valor_total_bruto = valor_produto_brl + valor_frete_brl;

    double imposto_importacao;
    double icms;
    double total_a_pagar;
    std::string mensagem_final;

    if (valor_produto_usd >= 2500.0) {
        imposto_importacao = valor_produto_brl * 0.60;
        double numerador_icms = valor_produto_brl + imposto_importacao;
        double base_final_icms = numerador_icms / (1.0 - aliquota_icms_decimal);
        icms = base_final_icms * aliquota_icms_decimal;
        total_a_pagar = valor_produto_brl + valor_frete_brl + imposto_importacao + icms;
        mensagem_final = "Impostos calculados sem o frete";
    } else {
        double base_impostos = valor_produto_brl + valor_frete_brl;
        imposto_importacao = base_impostos * 0.60;
        double numerador_icms = base_impostos + imposto_importacao;
        total_a_pagar = numerador_icms / (1.0 - aliquota_icms_decimal);
        icms = total_a_pagar * aliquota_icms_decimal;
        mensagem_final = "Impostos calculados com o frete";
    }

    double total_impostos = imposto_importacao + icms;
    
    std::cout << std::fixed << std::setprecision(2);
    std::cout << cotacao_dolar << std::endl;
    std::cout << valor_produto_brl << std::endl;
    std::cout << valor_frete_brl << std::endl;
    std::cout << valor_total_bruto << std::endl;
    std::cout << imposto_importacao << std::endl;
    std::cout << icms << std::endl;
    std::cout << total_impostos << std::endl;
    std::cout << total_a_pagar << std::endl;
    std::cout << mensagem_final << std::endl;

    return 0;
}
