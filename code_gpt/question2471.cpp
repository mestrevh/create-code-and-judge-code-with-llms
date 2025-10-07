/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Pedido {
    string nome;
    int tempo;
    string categoria;
    bool valido;

    bool operator<(const Pedido& outro) const {
        if (categoria != outro.categoria) {
            return categoria < outro.categoria;
        }
        if (tempo != outro.tempo) {
            return tempo < outro.tempo;
        }
        return nome < outro.nome;
    }
};

int main() {
    int M;
    cin >> M;
    cin.ignore();
    vector<vector<Pedido>> mesas(M);
    vector<int> totalPedidos(M, 0);
    vector<int> pedidosCorretos(M, 0);
    vector<string> pedidosAnotados;

    for (int i = 0; i < M; ++i) {
        int P;
        cin >> P;
        cin.ignore();
        for (int j = 0; j < P; ++j) {
            string linha;
            getline(cin, linha);
            if (linha.find(" ") == string::npos) {
                pedidosAnotados.push_back(linha);
                continue;
            }
            string nome;
            int tempo;
            string categoria;
            stringstream ss(linha);
            ss >> nome >> tempo >> categoria;

            mesas[i].emplace_back(Pedido{nome, tempo, categoria, true});
            totalPedidos[i]++;
        }
    }

    for (int i = 0; i < M; ++i) {
        for (const auto& pedido : mesas[i]) {
            if (pedido.valido) {
                pedidosCorretos[i]++;
            }
        }
        if (i > 0) {
            for (const auto& anotado : pedidosAnotados) {
                mesas[i].emplace_back(Pedido{anotado, 0, "", false});
            }
        }
        sort(mesas[i].begin(), mesas[i].end());

        cout << "Mesa " << (i + 1) << ": ";
        for (size_t j = 0; j < mesas[i].size(); ++j) {
            if (mesas[i][j].valido) {
                cout << mesas[i][j].nome;
                if (j < mesas[i].size() - 1) cout << ", ";
            }
        }
        cout << endl;
    }

    double porcentagem = 0.0;
    for (int i = 0; i < M; ++i) {
        porcentagem += (double)pedidosCorretos[i] / totalPedidos[i];
    }
    porcentagem = (porcentagem / M) * 100;

    if (porcentagem < 70) {
        cout << "Eu preciso esquecer o Ross, vou ligar pra ele e falar que eu o superei." << endl;
    } else if (porcentagem < 85) {
        cout << "Not bad, e so um trabalho temporario mesmo." << endl;
    } else {
        cout << "That's what I call closure, Ross!" << endl;
    }

    return 0;
}
