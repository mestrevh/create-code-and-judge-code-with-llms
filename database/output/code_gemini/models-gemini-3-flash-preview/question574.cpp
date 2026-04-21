/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double cotacao, icms_perc, prod_usd, frete_usd;
    if (!(cin >> cotacao >> icms_perc >> prod_usd >> frete_usd)) return 0;

    double prod_brl = prod_usd * cotacao;
    double frete_brl = frete_usd * cotacao;
    double total_prod_frete_brl = prod_brl + frete_brl;

    bool isento_frete = (prod_usd >= 2500.0);
    double base_calculo = isento_frete ? prod_brl : total_prod_frete_brl;
    
    double imposto_importacao = base_calculo * 0.60;
    double icms_decimal = icms_perc / 100.0;
    
    // Valor Final = (Base + Importação) / (1 - Aliquota ICMS)
    double valor_final_com_icms = (base_calculo + imposto_importacao) / (1.0 - icms_decimal);
    double valor_icms = valor_final_com_icms * icms_decimal;
    
    double total_a_pagar = valor_final_com_icms;
    if (isento_frete) {
        total_a_pagar += frete_brl;
    }

    cout << fixed << setprecision(2);
    cout << cotacao << "\n";
    cout << prod_brl << "\n";
    cout << frete_brl << "\n";
    cout << total_prod_frete_brl << "\n";
    cout << imposto_importacao << "\n";
    cout << valor_icms << "\n";
    cout << (imposto_importacao + valor_icms) << "\n";
    cout << total_a_pagar << "\n";
    
    if (isento_frete) {
        cout << "Impostos calculados sem o frete" << endl;
    } else {
        cout << "Impostos calculados com o frete" << endl;
    }

    return 0;
}