/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string tipo;
    if (!(cin >> tipo)) return 0;

    double valor;
    if (!(cin >> valor)) return 0;

    string rubrica = "";
    if (tipo != "PP") {
        cin >> rubrica;
    }

    if (tipo == "PP") {
        if (valor > 4000.0) {
            cout << "Excesso de pagamento para pessoal." << endl;
        } else {
            cout << "Pagamento liberado." << endl;
        }
    } else if (tipo == "PPF") {
        if (rubrica != "SERV") {
            cout << "Pessoa física não pode fornecer materiais para o serviço público." << endl;
        } else if (valor > 8000.0) {
            cout << "Excesso de pagamento para pessoa física." << endl;
        } else {
            cout << "Pagamento liberado." << endl;
        }
    } else if (tipo == "PPJ") {
        if (rubrica == "CAP") {
            if (valor > 5000000.0) {
                cout << "O valor para pagamento da rubrica de capital não pode exceder R$ 5M." << endl;
            } else {
                cout << "Pagamento liberado." << endl;
            }
        } else if (rubrica == "CUST") {
            if (valor > 2000000.0) {
                cout << "O valor para pagamento da rubrica de custeio não pode exceder R$ 2M." << endl;
            } else {
                cout << "Pagamento liberado." << endl;
            }
        } else if (rubrica == "SERV") {
            if (valor > 500000.0) {
                cout << "O valor para pagamento da rubrica de serviços não pode exceder R$ 500K." << endl;
            } else {
                cout << "Pagamento liberado." << endl;
            }
        } else {
            cout << "Pagamento liberado." << endl;
        }
    } else {
        cout << "Depesa inválida." << endl;
    }

    return 0;
}