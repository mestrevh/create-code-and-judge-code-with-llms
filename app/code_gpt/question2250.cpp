/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {
    int capacidade, pessoasNoEvento = 0;
    cin >> capacidade;
    queue<int> fila;
    
    string comando, tipo;
    while (cin >> comando >> tipo) {
        int num = (tipo == "VIP") ? 1 : stoi(tipo);
        if (comando == "Entraram") {
            if (pessoasNoEvento < capacidade) {
                pessoasNoEvento += num;
                cout << num << " pessoas entraram na casa. Atualmente ha " << pessoasNoEvento << " pessoas no evento.\n\n";
            } else {
                fila.push(num);
                int totalFila = 0;
                while (!fila.empty() && pessoasNoEvento < capacidade) {
                    int entrar = fila.front();
                    fila.pop();
                    if (pessoasNoEvento + entrar > capacidade) {
                        fila.push(entrar - (capacidade - pessoasNoEvento));
                        totalFila += capacity - pessoasNoEvento;
                        pessoasNoEvento = capacidade;
                    } else {
                        pessoasNoEvento += entrar;
                        totalFila += entrar;
                    }
                }
                cout << "Infelizmente a casa esta lotada, " << num << " pessoas foram redirecionadas para a fila.\n";
                cout << "A fila agora contem " << totalFila << " pessoas.\n\n";
            }
        } else if (comando == "Sairam") {
            pessoasNoEvento -= num;
            cout << num << " pessoas sairam da casa. Atualmente ha " << pessoasNoEvento << " pessoas no evento.\n";
            if (!fila.empty()) {
                int totalEntradas = 0;
                while (!fila.empty() && pessoasNoEvento < capacidade) {
                    int entrar = fila.front();
                    fila.pop();
                    if (pessoasNoEvento + entrar > capacidade) {
                        fila.push(entrar - (capacidade - pessoasNoEvento));
                        totalEntradas += capacidade - pessoasNoEvento;
                        pessoasNoEvento = capacidade;
                    } else {
                        pessoasNoEvento += entrar;
                        totalEntradas += entrar;
                    }
                }
                cout << totalEntradas << " pessoas da fila entraram na casa.\n";
                cout << (fila.empty() ? "Todos que estavam na fila de espera conseguiram entrar, atualmente nao ha fila de espera.\n" : "A fila agora contem " + to_string(fila.size()) + " pessoas.\n");
            }
        }
        cout << endl;
    }

    cout << "Vai Troinha, agora pede o ubii!" << endl;
    return 0;
}
