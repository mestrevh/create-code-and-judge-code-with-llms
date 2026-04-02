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

    long long capacity;
    if (!(cin >> capacity)) return 0;

    long long current_people = 0;
    long long queue_count = 0;
    string s, x;

    while (cin >> s >> x) {
        if (s == "Entraram") {
            if (x == "VIP") {
                current_people++;
                cout << "1 pessoas entraram na casa. Atualmente ha " << current_people << " pessoas no evento.\n";
            } else {
                long long val = stoll(x);
                long long space = capacity - current_people;
                if (space > 0) {
                    long long entering = min(val, space);
                    long long remaining = val - entering;
                    current_people += entering;
                    cout << entering << " pessoas entraram na casa. Atualmente ha " << current_people << " pessoas no evento.\n";
                    if (remaining > 0) {
                        queue_count += remaining;
                        cout << "Infelizmente a casa esta lotada, " << remaining << " pessoas foram redirecionadas para a fila.\n";
                        cout << "A fila agora contem " << queue_count << " pessoas.\n";
                    }
                } else {
                    queue_count += val;
                    cout << "Infelizmente a casa esta lotada, " << val << " pessoas foram redirecionadas para a fila.\n";
                    cout << "A fila agora contem " << queue_count << " pessoas.\n";
                }
            }
        } else if (s == "Sairam") {
            long long leaving = (x == "VIP" ? 1 : stoll(x));
            current_people -= leaving;
            cout << leaving << " pessoas sairam da casa. Atualmente ha " << current_people << " pessoas no evento.\n";

            if (queue_count > 0 && current_people < capacity) {
                long long space = capacity - current_people;
                long long from_queue = min(queue_count, space);
                current_people += from_queue;
                queue_count -= from_queue;
                cout << from_queue << " pessoas da fila entraram na casa.\n";
                if (queue_count == 0) {
                    cout << "Todos que estavam na fila de espera conseguiram entrar, atualmente nao ha fila de espera.\n";
                } else {
                    cout << "A fila agora contem " << queue_count << " pessoas.\n";
                }
            }
        }
        cout << "\n";
    }

    cout << "Vai Troinha, agora pede o ubii!\n";

    return 0;
}