/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void inverterLinhas(vector<string>& linhas, int index) {
    if (index < 0) return;
    cout << linhas[index] << endl;
    inverterLinhas(linhas, index - 1);
}

int main() {
    vector<string> linhas;
    string linha;

    while (getline(cin, linha)) {
        linhas.push_back(linha);
    }

    inverterLinhas(linhas, linhas.size() - 1);
    return 0;
}
