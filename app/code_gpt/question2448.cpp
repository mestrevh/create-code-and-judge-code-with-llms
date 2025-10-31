/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    int N, atual = 0;
    queue<int> fila;
    cin >> N;
    string comando, tipo;

    while (true) {
        cin >> comando;
        if (comando == "Sairam") break;
        cin >> tipo;
        int num_personas = (tipo == "CAPITAO") ? 1 : stoi(tipo);
        
        if (comando == "Entraram") {
            if (atual + num_personas <= N) {
                atual += num_personas;
                if (tipo == "CAPITAO")
                    cout << "Um CAPITAO entrou no Perola. Atualmente ha " << atual << " pessoas na tripulacao." << endl;
                else
                    cout << num_personas << " pessoas entraram no Perola. Atualmente ha " << atual << " pessoas na tripulacao." << endl;
            } else {
                fila.push(num_personas);
                cout << "Infelizmente o navio esta lotado, " << num_personas << " pessoas foram redirecionadas para a fila." << endl;
                cout << "A fila agora contem " << fila.size() << " pessoas." << endl;
            }
        } else if (comando == "Sairam") {
            atual -= num_personas;
            if (atual < 0) atual = 0;
            if (tipo == "CAPITAO") {
                cout << "Um CAPITAO desistiu da aventura. Atualmente ha " << atual << " pessoas na tripulacao." << endl;
            } else {
                cout << num_personas << " pessoas desistiram da aventura. Atualmente ha " << atual << " pessoas na tripulacao." << endl;
            }
            while (atual < N && !fila.empty()) {
                int entrada = fila.front();
                fila.pop();
                if (atual + entrada <= N) {
                    atual += entrada;
                    cout << entrada << " pessoas da fila entraram no Perola." << endl;
                } else {
                    fila.push(entrada);
                    break;
                }
            }
            cout << "A fila agora contem " << fila.size() << " pessoas." << endl;
        }
        cout << endl;
    }

    if (atual == 0) {
        cout << "Cade o Gibbs quando eu preciso dele?" << endl;
    } else {
        bool temCapitao = (atual > 0 && !fila.empty());
        if (temCapitao) {
            cout << "Preparem-se para a aventura de suas vidas marujos!!!!" << endl;
        } else {
            cout << "Jack? Onde esta o Jack? Como iremos viajar SEM O JACK?" << endl;
        }
    }
    return 0;
}
