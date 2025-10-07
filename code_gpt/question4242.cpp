/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int somaAlgarismos(int n) {
    int soma = 0;
    while (n > 0) {
        soma += n % 10;
        n /= 10;
    }
    return soma;
}

int calcularChave(const string& data) {
    int dia = stoi(data.substr(0, 2));
    int mes = stoi(data.substr(3, 2));
    int ano = stoi(data.substr(6, 4));
    return abs(somaAlgarismos(ano) - (somaAlgarismos(dia) + somaAlgarismos(mes)));
}

string decodificarMensagem(const string& mensagem, int chave, const string& clima) {
    string resultado;
    for (char c : mensagem) {
        if (c != ' ') {
            resultado += char(c - chave);
        } else {
            resultado += c;
        }
    }

    if (clima == "ensolarado") {
        reverse(resultado.begin(), resultado.end());
    } else if (clima == "chuvoso") {
        istringstream iss(resultado);
        string palavra, novaMensagem;
        while (iss >> palavra) {
            novaMensagem += (palavra.length() % 2 == 0) ?
                string(palavra.begin(), palavra.end()) :
                string(palavra.begin(), palavra.end());
            for (char& c : palavra) {
                c = (palavra.length() % 2 == 0) ? c + 1 : c - 1;
            }
            novaMensagem += palavra + " ";
        }
        resultado = novaMensagem;
    } else {
        return "Mensagem codificada invalida, provavelmente mais uma tentativa dos aliens de nos enganar!";
    }

    return resultado;
}

int main() {
    string clima, data, mensagem;
    getline(cin, clima);
    getline(cin, data);
    getline(cin, mensagem);

    int chave = calcularChave(data);
    string mensagemDecodificada = decodificarMensagem(mensagem, chave, clima);
    cout << mensagemDecodificada << endl;

    return 0;
}
