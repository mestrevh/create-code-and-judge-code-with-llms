/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int qtd, cedula;
    if (cin >> qtd >> cedula) {
        int valor_pago_centavos = (cedula == 2) ? 400 : (cedula * 100);
        int custo_refeicao_centavos = 325;
        
        int troco_por_refeicao = valor_pago_centavos - custo_refeicao_centavos;
        int troco_total_acumulado = qtd * troco_por_refeicao;
        
        int refeicoes_devidas = troco_total_acumulado / custo_refeicao_centavos;
        
        cout << refeicoes_devidas << endl;
    }

    return 0;
}