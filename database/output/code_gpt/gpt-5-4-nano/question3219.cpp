/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int contarOcorrencias(const string& s, char c) {
    int cont = 0;
    for (char x : s) {
        if (x == c) cont++;
    }
    return cont;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string seq;
    string alvoStr;
    if (!getline(cin, seq)) return 0;
    if (!getline(cin, alvoStr)) return 0;

    auto trim = [](string &t) {
        size_t start = 0;
        while (start < t.size() && isspace((unsigned char)t[start])) start++;
        size_t end = t.size();
        while (end > start && isspace((unsigned char)t[end - 1])) end--;
        t = t.substr(start, end - start);
    };

    trim(seq);
    trim(alvoStr);

    char alvo = alvoStr.empty() ? '\0' : alvoStr[0];

    int qtd = contarOcorrencias(seq, alvo);

    if (qtd >= 1) {
        cout << "O " << alvo << " ocorre " << qtd << " vezes na sequencia.";
    } else {
        cout << "Caractere nao encontrado.";
    }

    return 0;
}