/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

struct Produto {
    int codigo;
    string nome;
    float preco;
};

struct Continente {
    string nome;
    float taxaFrete;
};

Produto produtos[] = {
    { 701, "Abacaxi", 500.00 },
    { 702, "Laranja", 400.00 },
    { 703, "Café", 600.00 },
    { 704, "Caju", 450.00 },
    { 705, "Melancia", 300.00 },
    { 706, "Banana", 350.00 },
    { 707, "Soja", 900.00 },
    { 708, "Trigo", 750.00 },
    { 709, "Carne Bovina", 800.00 },
    { 710, "Carne Suína", 700.00 }
};

Continente continentes[] = {
    { "America", 5.00 },
    { "Europa", 10.00 },
    { "Asia", 15.00 },
    { "Africa", 20.00 },
    { "Oceania", 25.00 }
};

float dolarParaReal = 5.17;

void realizarNegociacao() {
    char comprador[31], pais[31], continente[11];
    int codigo, quantidade;
    
    cin.ignore();
    cin.getline(comprador, 31);
    cin.getline(pais, 31);
    cin.getline(continente, 11);
    cin >> codigo >> quantidade;

    int i;
    for (i = 0; i < sizeof(produtos) / sizeof(produtos[0]); i++) {
        if (produtos[i].codigo == codigo) break;
    }
    
    if (i == sizeof(produtos) / sizeof(produtos[0])) {
        cout << "Operacao invalida!" << endl;
        return;
    }

    float custoProduto = produtos[i].preco * quantidade;
    float custoFrete = continentes[0].taxaFrete; // Assume primeira taxa (exemplo)
    
    for (i = 0; i < sizeof(continentes) / sizeof(continentes[0]); i++) {
        if (continentes[i].nome == continente) {
            custoFrete = continentes[i].taxaFrete;
            break;
        }
    }
    
    float total = custoProduto + custoFrete;

    cout << comprador << endl;
    cout << pais << endl;
    cout << produtos[i].nome << endl;
    cout << "Valor do produto: U$ " << fixed << setprecision(2) << custoProduto << endl;
    cout << "Valor do frete: U$ " << fixed << setprecision(2) << custoFrete << endl;
    cout << "Valor total: U$ " << fixed << setprecision(2) << total << endl;
}

int main() {
    int N;
    cin >> N;
    
    if (N == 0) {
        cout << "Sem negociacoes por hoje!" << endl;
        return 0;
    }
    
    for (int i = 0; i < N; i++) {
        realizarNegociacao();
    }
    
    return 0;
}
