/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    int N, ovos = 0, fila = 0, filaShiny = 0;
    cin >> N;
    queue<int> filaEspera;

    string comando, tipo;
    while (cin >> comando >> tipo) {
        if (comando == "Entraram") {
            if (tipo == "SHINY") {
                if (ovos < N) {
                    ovos++;
                    cout << "Um SHINY entrou na incubadora. Atualmente ha " << ovos << " ovos na incubadora." << endl;
                } else {
                    filaEspera.push(1);
                    cout << "Infelizmente a incubadora esta lotada, 1 ovos foram redirecionadas para a fila." << endl;
                    fila++;
                }
            } else {
                int num = stoi(tipo);
                if (ovos + num <= N) {
                    ovos += num;
                    cout << num << " ovos entraram na incubadora. Atualmente ha " << ovos << " ovos na incubadora." << endl;
                } else {
                    filaEspera.push(num);
                    cout << "Infelizmente a incubadora esta lotada, " << num << " ovos foram redirecionadas para a fila." << endl;
                    fila += num;
                }
            }
        } else if (comando == "Sairam") {
            if (tipo == "SHINY") {
                if (ovos > 0) {
                    ovos--;
                    cout << "Um SHINY nasceu. Atualmente ha " << ovos << " ovos na incubadora." << endl;
                }
                if (!filaEspera.empty() && ovos < N) {
                    int toAdd = min(N - ovos, filaEspera.front());
                    filaShiny++;
                    ovos += toAdd;
                    filaEspera.front() -= toAdd;
                    if (filaEspera.front() == 0) {
                        filaEspera.pop();
                        cout << "Todos que estavam na fila de espera conseguiram entrar, atualmente nao ha fila de espera." << endl;
                    } else {
                        cout << toAdd << " ovos da fila entraram na incubadora." << endl;
                    }
                }
            } else {
                int num = stoi(tipo);
                if (num <= ovos) {
                    ovos -= num;
                    cout << num << " ovos chocaram. Atualmente ha " << ovos << " ovos na incubadora." << endl;
                }
                if (!filaEspera.empty() && ovos < N) {
                    int toAdd = min(N - ovos, filaEspera.front());
                    ovos += toAdd;
                    filaEspera.front() -= toAdd;
                    if (filaEspera.front() == 0) {
                        filaEspera.pop();
                        cout << "Todos que estavam na fila de espera conseguiram entrar, atualmente nao ha fila de espera." << endl;
                    } else {
                        cout << toAdd << " ovos da fila entraram na incubadora." << endl;
                    }
                }
            }
        }
        cout << endl;
    }

    if (ovos > 0) {
        if (filaShiny == ovos) cout << "Restaram apenas Pokemon raros na incubadora." << endl;
        else cout << "Restaram Pokemon raros e comuns na incubadora." << endl;
    } else {
        cout << "Nao restou nenhum Pokemon na incubadora." << endl;
    }
    return 0;
}
