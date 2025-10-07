/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

char calcularLetra(const string &s, int idx) {
    if (idx == s.size()) return 0;
    return s[idx] + calcularLetra(s, idx + 1);
}

char somaPalavra(const string &s) {
    int soma = calcularLetra(s, 0) % 90;
    if (soma < 65) {
        soma = 65 + (soma % 26);
    }
    return static_cast<char>(soma);
}

string processarPalavras(vector<string> &palavras, int idx) {
    if (idx >= palavras.size()) return "";
    return somaPalavra(palavras[idx]) + processarPalavras(palavras, idx + 1);
}

int main() {
    int n;
    cin >> n;
    cin.ignore();
    string input, resultado;
    getline(cin, input);
    vector<string> palavras;
    size_t pos = 0;

    while ((pos = input.find(' ')) != string::npos) {
        palavras.push_back(input.substr(0, pos));
        input.erase(0, pos + 1);
    }
    palavras.push_back(input);
    
    resultado = processarPalavras(palavras, 0);
    cout << resultado << endl;

    return 0;
}
