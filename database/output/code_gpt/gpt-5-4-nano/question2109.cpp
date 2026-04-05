/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static bool overFloat(double x, double lim) {
    return x > lim;
}

static bool isValidType(const string& s) {
    return s == "PPF" || s == "PPJ" || s == "PP";
}

static string typeFullToShort(const string& s) {
    if (s == "Pagamento para pessoa física (PPF)" || s == "Pagamento para pessoa física" || s == "PPF") return "PPF";
    if (s == "Pagamento para pessoa jurídica (PPJ)" || s == "Pagamento para pessoa jurídica" || s == "PPJ") return "PPJ";
    if (s == "Pagamento de pessoal (PP)" || s == "Pagamento de pessoal" || s == "PP") return "PP";
    return s;
}

static string normalizeRubrica(const string& s) {
    if (s == "Capital (CAP)" || s == "Capital") return "CAP";
    if (s == "Custeio (CUST)" || s == "Custeio") return "CUST";
    if (s == "Serviço (SERV)" || s == "Servico (SERV)" || s == "Serviço" || s == "Servico") return "SERV";
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string tipo;
    if (!(cin >> tipo)) return 0;
    double valor;
    cin >> valor;

    tipo = typeFullToShort(tipo);

    if (!isValidType(tipo)) {
        cout << "Depesa inválida.";
        return 0;
    }

    string rubrica = "";
    if (tipo != "PP") {
        // For safety, read rubrica if present
        if (cin >> rubrica) rubrica = normalizeRubrica(rubrica);
    }

    if (tipo == "PPF") {
        if (rubrica != "SERV" && !rubrica.empty()) {
            cout << "Pessoa física não pode fornecer materiais para o serviço público.";
            return 0;
        }
        if (overFloat(valor, 8000.0)) {
            cout << "Excesso de pagamento para pessoa física.";
            return 0;
        }
        cout << "Pagamento liberado.";
        return 0;
    }

    if (tipo == "PP") {
        if (overFloat(valor, 4000.0)) {
            cout << "Excesso de pagamento para pessoal.";
            return 0;
        }
        cout << "Pagamento liberado.";
        return 0;
    }

    // PPJ
    rubrica = normalizeRubrica(rubrica);
    if (rubrica == "CAP") {
        if (overFloat(valor, 5000000.0)) {
            cout << "O valor para pagamento da rubrica de capital não pode exceder R$ 5M.";
            return 0;
        }
    } else if (rubrica == "CUST") {
        if (overFloat(valor, 2000000.0)) {
            cout << "O valor para pagamento da rubrica de custeio não pode exceder R$ 2M.";
            return 0;
        }
    } else if (rubrica == "SERV") {
        if (overFloat(valor, 500000.0)) {
            cout << "O valor para pagamento da rubrica de serviços não pode exceder R$ 500K.";
            return 0;
        }
    }
    cout << "Pagamento liberado.";
    return 0;
}