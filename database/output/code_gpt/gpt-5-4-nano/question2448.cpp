/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    if (!(cin >> N)) return 0;

    long long trip = 0;
    long long fila = 0;
    bool temCapitao = false;

    string s;
    while (cin >> s) {
        if (s == "Entraram") {
            string x;
            cin >> x;
            long long qtd = 0;
            bool cap = false;
            if (x == "CAPITAO") cap = true;
            else qtd = stoll(x);

            if (cap) {
                trip += 1;
                cout << "Um CAPITAO entrou no Perola. Atualmente ha " << trip << " pessoas na tripulacao.\n\n";
                temCapitao = true;
            } else {
                if (trip + qtd <= N) {
                    trip += qtd;
                    cout << qtd << " pessoas entraram no Perola. Atualmente ha " << trip << " pessoas na tripulacao.\n\n";
                } else {
                    long long redir = (trip >= N ? qtd : (trip + qtd - N));
                    fila += redir;
                    cout << "Infelizmente o navio esta lotado, " << redir << " pessoas foram redirecionadas para a fila.\n";
                    cout << "A fila agora contem " << fila << " pessoas.\n\n";
                }
            }
        } else if (s == "Sairam") {
            string x;
            cin >> x;
            long long qtd = 0;
            bool cap = false;
            if (x == "CAPITAO") cap = true;
            else qtd = stoll(x);

            if (cap) {
                if (trip > 0) trip -= 1;
                cout << "Um CAPITAO desistiu da aventura. Atualmente ha " << trip << " pessoas na tripulacao.\n\n";
            } else {
                if (qtd > trip) qtd = trip;
                trip -= qtd;
                cout << qtd << " pessoas desistiram da aventura. Atualmente ha " << trip << " pessoas na tripulacao.\n";

                if (fila > 0) {
                    long long espaco = N - trip;
                    if (espaco > 0) {
                        long long entrarFila = min(fila, espaco);
                        trip += entrarFila;
                        fila -= entrarFila;
                        cout << entrarFila << " pessoas da fila entraram no Perola.\n";
                        if (fila > 0) cout << "A fila agora contem " << fila << " pessoas.\n\n";
                        else cout << "Todos que estavam na fila de espera conseguiram entrar, atualmente nao ha fila de espera.\n\n";
                    } else {
                        cout << "A fila agora contem " << fila << " pessoas.\n\n";
                    }
                } else {
                    cout << "\n";
                }
            }
        }
    }

    if (trip == 0) {
        cout << "Cade o Gibbs quando eu preciso dele?";
        return 0;
    }

    if (temCapitao && trip > 0) {
        cout << "Preparem-se para a aventura de suas vidas marujos!!!!";
    } else {
        cout << "Jack? Onde esta o Jack? Como iremos viajar SEM O JACK?";
    }

    return 0;
}