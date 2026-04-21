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

    int N;
    if (!(cin >> N)) return 0;

    long long curr = 0;
    long long common = 0;
    long long shiny = 0;
    long long queue_eggs = 0;

    string cmd, x_str;
    while (cin >> cmd >> x_str) {
        if (cmd == "Entraram") {
            if (x_str == "SHINY") {
                curr++;
                shiny++;
                cout << "Um SHINY entrou na incubadora. Atualmente ha " << curr << " ovos na incubadora.\n";
            } else {
                long long val = stoll(x_str);
                if (curr < N) {
                    curr += val;
                    common += val;
                    cout << val << " ovos entraram na incubadora. Atualmente ha " << curr << " ovos na incubadora.\n";
                } else {
                    queue_eggs += val;
                    cout << "Infelizmente a incubadora esta lotada, " << val << " ovos foram redirecionadas para a fila.\n";
                    cout << "A fila agora contem " << queue_eggs << " ovos.\n";
                }
            }
        } else if (cmd == "Sairam") {
            if (x_str == "SHINY") {
                curr--;
                shiny--;
                cout << "Um SHINY nasceu. Atualmente ha " << curr << " ovos na incubadora.\n";
            } else {
                long long val = stoll(x_str);
                curr -= val;
                common -= val;
                cout << val << " ovos chocaram. Atualmente ha " << curr << " ovos na incubadora.\n";
            }

            if (queue_eggs > 0 && curr < N) {
                long long to_enter = min(queue_eggs, (long long)N - curr);
                cout << to_enter << " ovos da fila entraram na incubadora.\n";
                curr += to_enter;
                common += to_enter;
                queue_eggs -= to_enter;
                if (queue_eggs > 0) {
                    cout << "A fila agora contem " << queue_eggs << " ovos.\n";
                } else {
                    cout << "Todos que estavam na fila de espera conseguiram entrar, atualmente nao ha fila de espera.\n";
                }
            }
        }
        cout << "\n";
    }

    if (shiny > 0 && common > 0) {
        cout << "Restaram Pokemon raros e comuns na incubadora.\n";
    } else if (shiny > 0 && common == 0) {
        cout << "Restaram apenas Pokemon raros na incubadora.\n";
    } else if (shiny == 0 && common > 0) {
        cout << "Nao restou nenhum Pokemon raro na incubadora.\n";
    } else {
        cout << "Nao restou nenhum Pokemon na incubadora.\n";
    }

    return 0;
}