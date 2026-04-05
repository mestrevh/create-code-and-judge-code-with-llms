/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> nomes;
    vector<int> senhas;
    vector<char> situacoes;

    string nome;
    while (true) {
        if (!getline(cin, nome)) return 0;
        if (!nome.empty() && nome.back() == '\r') nome.pop_back();
        if (nome == "SAIR") break;
        int senha;
        char situacao;
        if (!(cin >> senha)) break;
        cin >> situacao;
        nomes.push_back(nome);
        senhas.push_back(senha);
        situacoes.push_back(situacao);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if ((int)nomes.size() >= 100) {
            string dummy;
            while (cin && cin.peek() != EOF) {
                streampos pos = cin.tellg();
                if (!getline(cin, dummy)) break;
                if (dummy == "SAIR") break;
                int s; char st;
                if (!(cin >> s)) break;
                cin >> st;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            break;
        }
    }

    unordered_map<int, pair<string,char>> mp;
    for (size_t i = 0; i < nomes.size(); i++) {
        mp[senhas[i]] = {nomes[i], situacoes[i]};
    }

    int q;
    while (cin >> q) {
        if (q == -1) break;
        auto it = mp.find(q);
        if (it == mp.end()) {
            cout << "Seja bem-vindo(a)! Procure a recepção!" << "\n";
        } else {
            const string &n = it->second.first;
            char s = it->second.second;
            if (s == 'P') {
                cout << n << ", seja bem-vindo(a)!" << "\n";
            } else {
                cout << "Não está esquecendo de algo, " << n << "? Procure a recepção!" << "\n";
            }
        }
    }
    return 0;
}