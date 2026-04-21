/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int idade, total_vendas_count = 0, count_vista = 0, min_idade = INT_MAX;
    float valor, total_vista = 0.0f, total_cartao = 0.0f, max_compra = 0.0f;
    char tipo, continua;

    while (cin >> idade >> valor >> tipo >> continua) {
        total_vendas_count++;
        
        if (idade < min_idade) {
            min_idade = idade;
        }
        
        if (valor > max_compra) {
            max_compra = valor;
        }
        
        if (tipo == 'V') {
            total_vista += valor;
            count_vista++;
        } else if (tipo == 'C') {
            total_cartao += valor;
        }
        
        if (continua == 'N') {
            break;
        }
    }

    cout << total_vendas_count << "\n";
    
    if (total_vista == 0.0f) {
        cout << 0 << "\n";
    } else {
        cout << fixed << setprecision(2) << total_vista << "\n";
    }
    
    if (total_cartao == 0.0f) {
        cout << 0 << "\n";
    } else {
        cout << fixed << setprecision(2) << total_cartao << "\n";
    }
    
    cout << min_idade << "\n";
    
    if (max_compra == 0.0f) {
        cout << 0 << "\n";
    } else {
        cout << fixed << setprecision(2) << max_compra << "\n";
    }
    
    float media_vista = 0.0f;
    if (count_vista > 0) {
        media_vista = total_vista / (float)count_vista;
    }
    
    if (media_vista == 0.0f) {
        cout << 0 << endl;
    } else {
        cout << fixed << setprecision(2) << media_vista << endl;
    }

    return 0;
}