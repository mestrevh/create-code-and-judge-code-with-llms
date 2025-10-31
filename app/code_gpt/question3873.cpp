/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();

    vector<string> beneficiados;
    vector<string> prejudicados;
    vector<double> valoresBeneficiados;
    vector<double> valoresPrejudicados;

    for (int i = 0; i < n; ++i) {
        string nome;
        string numeroCartao;
        int cvv;
        double valor;

        getline(cin, nome);
        getline(cin, numeroCartao);
        cin >> cvv >> valor;
        cin.ignore();

        int somaDigitos = 0;
        for (char c : numeroCartao) {
            somaDigitos += c - '0';
        }

        if (somaDigitos >= cvv) {
            beneficiados.push_back(nome);
            valoresBeneficiados.push_back(0.0);
        } else {
            prejudicados.push_back(nome);
            valoresPrejudicados.push_back(valor * (somaDigitos - cvv));
        }
    }

    cout << "Um total de " << beneficiados.size() << " clientes se beneficiaram da nova politica!" << endl;
    for (size_t i = 0; i < beneficiados.size(); ++i) {
        cout << beneficiados[i] << " " << fixed << setprecision(2) << valoresBeneficiados[i] << endl;
    }

    cout << "No entanto, " << prejudicados.size() << " clientes nao se beneficiaram da nova politica." << endl;
    for (size_t i = 0; i < prejudicados.size(); ++i) {
        cout << prejudicados[i] << " " << fixed << setprecision(2) << valoresPrejudicados[i] << endl;
    }

    return 0;
}
