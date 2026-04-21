/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    if (!(cin >> n)) return 0;

    long long cur = 0;
    long long caps = 0;
    long long q = 0;

    string cmd, val;
    while (cin >> cmd >> val) {
        if (cmd == "Entraram") {
            if (val == "CAPITAO") {
                cur++;
                caps++;
                cout << "Um CAPITAO entrou no Perola. Atualmente ha " << cur << " pessoas na tripulacao.\n";
            } else {
                long long x = stoll(val);
                if (cur < n) {
                    long long can = n - cur;
                    long long ent = min(x, can);
                    long long red = x - ent;
                    cur += ent;
                    cout << ent << " pessoas entraram no Perola. Atualmente ha " << cur << " pessoas na tripulacao.\n";
                    if (red > 0) {
                        q += red;
                        cout << "Infelizmente o navio esta lotado, " << red << " pessoas foram redirecionadas para a fila.\n";
                        cout << "A fila agora contem " << q << " pessoas.\n";
                    }
                } else {
                    q += x;
                    cout << "Infelizmente o navio esta lotado, " << x << " pessoas foram redirecionadas para a fila.\n";
                    cout << "A fila agora contem " << q << " pessoas.\n";
                }
            }
        } else if (cmd == "Sairam") {
            if (val == "CAPITAO") {
                cur--;
                caps--;
                cout << "Um CAPITAO desistiu da aventura. Atualmente ha " << cur << " pessoas na tripulacao.\n";
            } else {
                long long x = stoll(val);
                cur -= x;
                cout << x << " pessoas desistiram da aventura. Atualmente ha " << cur << " pessoas na tripulacao.\n";
            }
            
            if (q > 0 && cur < n) {
                long long move = min(q, n - cur);
                cur += move;
                q -= move;
                cout << move << " pessoas da fila entraram no Perola.\n";
                if (q > 0) {
                    cout << "A fila agora contem " << q << " pessoas.\n";
                } else {
                    cout << "Todos que estavam na fila de espera conseguiram entrar, atualmente nao ha fila de espera.\n";
                }
            }
        }
        cout << "\n";
    }

    if (cur == 0) {
        cout << "Cade o Gibbs quando eu preciso dele?\n";
    } else if (caps > 0) {
        if (cur == caps) {
            cout << "Sem tripulacao?? E quem voce acha que fara o trabalho sujo??\n";
        } else {
            cout << "Preparem-se para a aventura de suas vidas marujos!!!!\n";
        }
    } else {
        cout << "Jack? Onde esta o Jack? Como iremos viajar SEM O JACK?\n";
    }

    return 0;
}