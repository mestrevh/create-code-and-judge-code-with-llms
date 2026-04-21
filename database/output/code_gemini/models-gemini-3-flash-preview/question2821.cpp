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

    int dia, opcao;
    double preco;

    cout << "Digite dia da semana: (1-SEG a 7-DOM)" << endl;
    if (!(cin >> dia)) return 0;
    cout << "Digite preco do produto em reais:" << endl;
    if (!(cin >> preco)) return 0;
    cout << "Digite a opcao do produto: (2-prata 1-ouro)" << endl;
    if (!(cin >> opcao)) return 0;

    string dias_str[] = {"", "seg", "ter", "qua", "qui", "sex", "sab", "dom"};
    double final_preco;

    if ((dia >= 1 && dia <= 3) && (opcao == 1)) {
        final_preco = preco / 2.0;
    } else if ((dia == 4 || dia == 5) && (preco >= 10.0 && preco <= 100.0)) {
        final_preco = preco / 3.0;
    } else if (dia == 6 && opcao == 2) {
        final_preco = preco * 3.0;
    } else {
        final_preco = preco * 2.0;
    }

    if (dia >= 1 && dia <= 7) {
        cout << "O preco do produto no dia " << dias_str[dia] << " e R$ " << fixed << setprecision(2) << final_preco << endl;
    }

    return 0;
}