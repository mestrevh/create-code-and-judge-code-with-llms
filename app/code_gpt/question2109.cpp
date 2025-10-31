/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    string tipo;
    float valor;
    cin >> tipo >> valor;

    if (tipo == "PPF") {
        string rubrica;
        if (valor > 8000) {
            cout << "Excesso de pagamento para pessoa física." << endl;
            return 0;
        }
        if (valor <= 8000) {
            if (cin >> rubrica) {
                if (rubrica != "SERV") {
                    cout << "Pessoa física não pode fornecer materiais para o serviço público." << endl;
                    return 0;
                }
            }
        }
        cout << "Pagamento liberado." << endl;
    } else if (tipo == "PP") {
        if (valor > 4000) {
            cout << "Excesso de pagamento para pessoal." << endl;
        } else {
            cout << "Pagamento liberado." << endl;
        }
    } else if (tipo == "PPJ") {
        string rubrica;
        if (cin >> rubrica) {
            if (rubrica == "CAP") {
                if (valor > 5000000) {
                    cout << "O valor para pagamento da rubrica de capital não pode exceder R$ 5M." << endl;
                } else {
                    cout << "Pagamento liberado." << endl;
                }
            } else if (rubrica == "CUST") {
                if (valor > 2000000) {
                    cout << "O valor para pagamento da rubrica de custeio não pode exceder R$ 2M." << endl;
                } else {
                    cout << "Pagamento liberado." << endl;
                }
            } else if (rubrica == "SERV") {
                if (valor > 500000) {
                    cout << "O valor para pagamento da rubrica de serviços não pode exceder R$ 500K." << endl;
                } else {
                    cout << "Pagamento liberado." << endl;
                }
            } else {
                cout << "Despesa inválida." << endl;
            }
        }
    } else {
        cout << "Despesa inválida." << endl;
    }
    
    return 0;
}
