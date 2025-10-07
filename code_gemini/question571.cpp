/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int qtd, valor_cedula;
    std::cin >> qtd >> valor_cedula;

    int pagamento_centavos;

    if (valor_cedula == 2) {
        pagamento_centavos = 400;
    } else {
        pagamento_centavos = valor_cedula * 100;
    }

    const int custo_refeicao_centavos = 325;
    
    long long troco_total_centavos = (long long)(pagamento_centavos - custo_refeicao_centavos) * qtd;
    
    int refeicoes_gratis = troco_total_centavos / custo_refeicao_centavos;

    std::cout << refeicoes_gratis << std::endl;

    return 0;
}
