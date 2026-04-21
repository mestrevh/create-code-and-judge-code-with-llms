/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

/**
 * Procedimento que realiza a conversão de reais para dólares e exibe o resultado formatado.
 * 
 * @param reais Valor em reais a ser convertido.
 */
void converter_moeda(double reais) {
    const double taxa_cambio = 5.75;
    double dolares = reais / taxa_cambio;

    // A saída exibe o valor em reais seguido pela conversão em dólares.
    // Conforme os casos de teste, o valor em reais é impresso e o valor
    // em dólares é formatado com duas casas decimais.
    cout << "A cotação de R$" << reais << " para dólar é US$" << fixed << setprecision(2) << dolares << endl;
}

int main() {
    // Otimização de entrada e saída padrão do C++.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double valor_reais;
    
    // Leitura do valor em reais (tipo real/double).
    if (cin >> valor_reais) {
        converter_moeda(valor_reais);
    }

    return 0;
}