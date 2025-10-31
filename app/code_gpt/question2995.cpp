/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double peso, comprimento, largura, profundidade;
    double custoPeso, custoTamanho;

    while (true) {
        cin >> peso;
        if (peso > 0) {
            cout << "Peso valido!" << endl;
            break;
        } else {
            cout << "Peso invalido!" << endl;
        }
    }

    while (true) {
        cin >> comprimento >> largura >> profundidade;
        if (comprimento > 0 && largura > 0 && profundidade > 0) {
            cout << "Dimensoes validas!" << endl;
            break;
        } else {
            cout << "Dimensoes invalidas!" << endl;
        }
    }

    double maiorDimensao = max({comprimento, largura, profundidade});
    double somaDimensoes = comprimento + largura + profundidade;

    if (peso > 500.0 || maiorDimensao > 28.0 || somaDimensoes > 52.0) {
        cout << "Este pacote nao atende os limites para envio no caixa de autoatendimento, dirija-se ao balcao de atendimento para posta-lo!" << endl;
    } else {
        custoPeso = (peso <= 100.0) ? 1.50 : (peso <= 200.0) ? 2.00 : (peso <= 300.0) ? 2.50 : (peso <= 400.0) ? 3.00 : 3.50;
        custoTamanho = (somaDimensoes <= 20.0) ? 2.00 : (somaDimensoes <= 30.0) ? 3.00 : 4.00;
        double custoTotal = custoPeso + custoTamanho;

        cout << fixed << setprecision(2) << "Custo total do envio: R$ " << custoTotal << endl;
    }

    return 0;
}
