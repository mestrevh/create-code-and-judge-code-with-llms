/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

bool isGerundio(const string &word) {
    return word.ends_with("ando") || word.ends_with("endo") || word.ends_with("indo");
}

bool isParticipio(const string &word) {
    return word.ends_with("ado") || word.ends_with("ido");
}

bool isInfinitivo(const string &word) {
    return word.ends_with("ar") || word.ends_with("er") || word.ends_with("ir");
}

int main() {
    vector<string> gerundio, participio, infinitivo, outros;
    string word;

    while (true) {
        getline(cin, word);
        if (word == "fim") {
            if (gerundio.empty() && participio.empty() && infinitivo.empty()) {
                cout << "Programa finalizado, você digitou apenas a palavra *fim*, desejando encerrar o programa." << endl;
            } else {
                break;
            }
        }
        if (isGerundio(word)) {
            gerundio.push_back(word);
        } else if (isParticipio(word)) {
            participio.push_back(word);
        } else if (isInfinitivo(word)) {
            infinitivo.push_back(word);
        } else {
            outros.push_back(word);
        }
    }

    if (!gerundio.empty()) {
        cout << "As palavras que você digitou no gerúndio foram as seguintes: ";
        for (size_t i = 0; i < gerundio.size(); ++i) {
            cout << gerundio[i] << (i < gerundio.size() - 1 ? ", " : ".") << endl;
        }
    } else {
        cout << "Você não digitou nenhuma palavra no <u>gerúndio</u>!" << endl;
    }

    if (!participio.empty()) {
        cout << "As palavras que você digitou estão no particípio: ";
        for (size_t i = 0; i < participio.size(); ++i) {
            cout << participio[i] << (i < participio.size() - 1 ? ", " : ".") << endl;
        }
    } else {
        cout << "Você não digitou nenhuma palavra no <u>particípio</u>!" << endl;
    }

    if (!infinitivo.empty()) {
        cout << "As palavras que você digitou no infinitivo são: ";
        for (size_t i = 0; i < infinitivo.size(); ++i) {
            cout << infinitivo[i] << (i < infinitivo.size() - 1 ? ", " : ".") << endl;
        }
    } else {
        cout << "Você não digitou nenhuma palavra no <u>infinitivo</u>!" << endl;
    }

    if (!outros.empty()) {
        cout << "As palavras que você digitou que não estão no gerúndio, particípio ou infinitivo e/são: ";
        for (size_t i = 0; i < outros.size(); ++i) {
            cout << outros[i] << (i < outros.size() - 1 ? ", " : ".") << endl;
        }
    }

    return 0;
}
