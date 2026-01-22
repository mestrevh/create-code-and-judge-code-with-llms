/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    int socios = 0, brindes = 0;
    double total = 0.0;
    
    for (int i = 0; i < 5; i++) {
        string tamanho, lavagem, tipo_cliente;
        cin >> tamanho >> std::ws;  // Para consumir espaço em branco
        getline(cin, lavagem);
        getline(cin, tipo_cliente);
        
        double preco = 0.0;
        
        if (tamanho == "pequeno") {
            if (lavagem == "com cera") {
                preco = (tipo_cliente == "Sócio") ? 30 : 40;
                brindes++;
            } else {
                preco = (tipo_cliente == "Sócio") ? 20 : 30;
            }
        } else { // tamanho == "grande"
            if (lavagem == "com cera") {
                preco = (tipo_cliente == "Sócio") ? 60 : 80;
                brindes++;
            } else {
                preco = (tipo_cliente == "Sócio") ? 40 : 50;
            }
        }
        
        if (tipo_cliente == "Sócio") {
            socios++;
        }
        
        total += preco;
    }
    
    cout << socios << endl;
    cout << brindes << endl;
    cout << fixed << setprecision(2) << total << endl;
    
    return 0;
}
