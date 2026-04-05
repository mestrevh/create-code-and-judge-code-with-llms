/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;
    string line;
    getline(cin, line);

    map<string, long long> stock;
    vector<string> outputs;

    auto trimCR = [](string &s){
        if (!s.empty() && s.back() == '\r') s.pop_back();
    };

    for (int i = 0; i < N; i++) {
        string cmd;
        while (true) {
            if (!getline(cin, cmd)) cmd.clear();
            trimCR(cmd);
            if (!cmd.empty() || cin.eof()) break;
            if (cmd.empty()) continue;
        }
        if (cmd.empty() && cin.eof()) break;

        string name;
        long long qty = 0;
        bool invalid = false;

        if (!getline(cin, name)) name.clear();
        trimCR(name);

        if (!(cin >> qty)) qty = 0;

        getline(cin, line);

        if (qty < 0) invalid = true;

        if (cmd == "Registro") {
            if (invalid) {
                outputs.push_back("Comando invalido");
                continue;
            }
            if (stock.count(name)) outputs.push_back("Produto ja registrado");
            else {
                stock[name] = 0;
                outputs.push_back("Produto registrado com sucesso");
            }
        } else if (cmd == "Venda") {
            if (invalid) {
                outputs.push_back("Comando invalido");
                continue;
            }
            auto it = stock.find(name);
            if (it == stock.end()) outputs.push_back("Produto nao registrado");
            else if (it->second < qty) outputs.push_back("Sem  estoque para a Venda");
            else {
                it->second -= qty;
                outputs.push_back("Venda realizada com sucesso");
            }
        } else if (cmd == "Recarga") {
            if (invalid) {
                outputs.push_back("Comando invalido");
                continue;
            }
            auto it = stock.find(name);
            if (it == stock.end()) outputs.push_back("Produto nao registrado");
            else {
                it->second += qty;
                outputs.push_back("Recarga realizada com sucesso");
            }
        } else {
            outputs.push_back("Comando invalido");
        }
    }

    for (auto &s : outputs) cout << s << "\n";
    for (auto &p : stock) cout << p.first << ": " << p.second << "\n";

    return 0;
}