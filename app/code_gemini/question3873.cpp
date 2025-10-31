/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <utility>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    cin.ignore();

    vector<pair<string, double>> beneficiados;
    vector<pair<string, double>> prejudicados;

    for (int i = 0; i < n; ++i) {
        string nome;
        string numero_cartao;
        int cvv;
        double valor_fatura;

        getline(cin, nome);
        cin >> numero_cartao;
        cin >> cvv;
        cin >> valor_fatura;
        cin.ignore();

        int soma_digitos = 0;
        for (char digito : numero_cartao) {
            soma_digitos += (digito - '0');
        }

        if (soma_digitos >= cvv) {
            beneficiados.push_back({nome, 0.0});
        } else {
            double novo_valor = valor_fatura * (cvv - soma_digitos);
            prejudicados.push_back({nome, novo_valor});
        }
    }

    cout << fixed << setprecision(2);

    cout << "Um total de " << beneficiados.size() << " clientes se beneficiaram da nova politica!" << endl;
    for (const auto& p : beneficiados) {
        cout << p.first << " " << p.second << endl;
    }

    cout << "No entanto, " << prejudicados.size() << " clientes nao se beneficiaram da nova politica." << endl;
    for (const auto& p : prejudicados) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}
