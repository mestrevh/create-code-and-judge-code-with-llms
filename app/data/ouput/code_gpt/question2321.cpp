/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int calcularValorNome(const string &nome) {
    int soma = 0;
    for (char c : nome) {
        soma += static_cast<int>(c);
    }
    if (nome == "Troy bolton" || nome == "Gabriella Montez" || nome == "Sharpay Evans" || nome == "Ryan Evans") {
        soma += 350;
    }
    return soma;
}

int calcularPaciência(int paciência, int i, int N) {
    return paciência * (1 - (i / 100.0));
}

string encontrarVencedor(const vector<string> &candidatos, int paciência, int i, string vencedor, int &max) {
    if (i >= candidatos.size()) return vencedor;
    int valor = calcularValorNome(candidatos[i]) * calcularPaciência(paciência, i, candidatos.size());
    if (valor > max) {
        max = valor;
        vencedor = candidatos[i];
    }
    return encontrarVencedor(candidatos, paciência, i + 1, vencedor, max);
}

int main() {
    int paciência, N;
    cin >> paciência >> N;
    cin.ignore();
    vector<string> candidatos(N);
    
    for (int i = 0; i < N; ++i) {
        getline(cin, candidatos[i]);
    }

    int max = 0;
    string vencedor = "";
    vencedor = encontrarVencedor(candidatos, paciência, 0, vencedor, max);
    
    cout << "O grande vencedor(a) do papel principal desse ano foi " << vencedor << "!" << endl;
    return 0;
}
