/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static string toUpperChar(char c) {
    return string(1, (char)toupper((unsigned char)c));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string nome;
    int cont = 0;
    while (cont < 5 && (cin >> ws, getline(cin, nome))) {
        if (!nome.empty() && nome.back() == '\r') nome.pop_back();
        if (nome == "SAIR") break;

        string data, cidade;
        int idade;

        getline(cin, data);
        if (!data.empty() && data.back() == '\r') data.pop_back();
        getline(cin, cidade);
        if (!cidade.empty() && cidade.back() == '\r') cidade.pop_back();
        string line;
        while (true) {
            if (!(cin >> idade)) return 0;
            break;
        }

        string d = data;
        if (!d.empty() && d.back() == '\r') d.pop_back();

        vector<string> parts;
        {
            string cur;
            for (char ch : d) {
                if (ch == '/') {
                    parts.push_back(cur);
                    cur.clear();
                } else cur.push_back(ch);
            }
            parts.push_back(cur);
        }

        string dia = parts.size() > 0 ? parts[0] : "";
        string mes = parts.size() > 1 ? parts[1] : "";

        if (dia.size() == 1) dia = "0" + dia;
        if (mes.size() == 1) mes = "0" + mes;

        string senha;
        int i = 0;
        int L = (int)nome.size();
        int LC = (int)cidade.size();
        auto getNome = [&](int idx) -> char { return idx < L ? nome[idx] : '\0'; };
        auto getCidade = [&](int idx) -> char { return idx < LC ? cidade[idx] : '\0'; };

        while ((int)senha.size() < 5 + 2 + 4 + (int)to_string(idade).size()) {
            if (i % 2 == 0) {
                int idxNome = i / 2;
                if (idxNome < 5) {
                    senha.push_back(getNome(idxNome));
                } else break;
            } else {
                int k = i / 2;
                if (k == 0) {
                    if (dia.size() >= 1) senha.push_back(dia[0]);
                } else if (k == 1) {
                    if (mes.size() >= 1) senha.push_back(mes[0]);
                } else {
                    if (k == 2) break;
                }
            }
            i++;
            if (i >= 10) break;
        }

        int added = (int)senha.size();
        string nomePart = nome.substr(0, 5);
        string cityPart = cidade.substr(0, min(4, (int)cidade.size()));
        string diaPart = dia;
        string mesPart = mes;

        if (added < 5 + 2) {
            senha.clear();
            for (int t = 0; t < 5; t++) senha.push_back(nomePart[t]);
            senha.insert(senha.begin() + 1, diaPart[0]); 
            senha.insert(senha.begin() + 2, mesPart[0]);
            senha = "";
        }

        senha.clear();
        for (int t = 0; t < 5; t++) {
            senha.push_back(nomePart[t]);
            if (t == 0) senha.push_back(diaPart[0]);
            if (t == 1) senha.push_back(mesPart[0]);
        }

        int cityUse = min(4, (int)cidade.size());
        for (int t = 0; t < cityUse; t++) senha.push_back(cidade[t]);

        senha += to_string(idade);

        cout << "Nome: " << nome << "\n";
        cout << "Data de Nascimento: " << dia << "/" << mes;
        if (parts.size() > 2) cout << "/" << parts[2];
        cout << "\n";
        cout << "Cidade Natal: " << cidade << "\n";
        cout << "Idade: " << idade << " anos\n";
        cout << "Senha: " << senha << "\n\n";

        cont++;
    }
    return 0;
}