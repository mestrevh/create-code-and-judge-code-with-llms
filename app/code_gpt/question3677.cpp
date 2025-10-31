/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    float totalDinheiro;
    cin >> totalDinheiro;
    
    int propulsor1, propulsor2;
    cin >> propulsor1 >> propulsor2;
    
    float preco1, preco2;
    cin >> preco1 >> preco2;
    
    float dividaJabbavitz;
    cin >> dividaJabbavitz;
    
    float conserto = 0;
    if (propulsor1 == 1) conserto += preco1;
    if (propulsor2 == 1) conserto += preco2;
    if (propulsor1 == 1 && propulsor2 == 1) conserto -= max(preco1, preco2) * 0.12;
    
    bool podePagarDivida = totalDinheiro >= dividaJabbavitz;
    bool podeConsertarNave = totalDinheiro >= conserto;
    
    if (podePagarDivida && podeConsertarNave) {
        cout << "Sherliro livre do Jabbavitz e podendo voar" << endl;
    } else if (!podePagarDivida && podeConsertarNave) {
        cout << "Sherliro consertou mas ta lascado com o Jabbavitz" << endl;
        cout << fixed << setprecision(2) << "faltam " << dividaJabbavitz - totalDinheiro << " Napoleocoins" << endl;
    } else {
        cout << "Sherliro vai ser perseguido hoje e ainda ta sem nave" << endl;
        cout << fixed << setprecision(2) << "faltam " << dividaJabbavitz - totalDinheiro << " Napoleocoins" << endl;
        cout << fixed << setprecision(2) << "faltam " << conserto - totalDinheiro << " Napoleocoins" << endl;
    }
    
    return 0;
}
