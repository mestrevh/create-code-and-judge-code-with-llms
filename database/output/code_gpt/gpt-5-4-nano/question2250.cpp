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

    long long inside = 0;
    long long q = 0;

    string line;
    getline(cin, line);

    while (true) {
        streampos pos = cin.tellg();
        if (!getline(cin, line)) break;

        if (line.empty()) continue;

        while (line.size() && (line.back() == '\r' || line.back() == '\n')) line.pop_back();
        if (line.empty()) continue;

        stringstream ss(line);
        string S;
        ss >> S;

        bool isEnter = (S == "Entraram");
        if (!(S == "Entraram" || S == "Sairam")) continue;

        string X;
        if (!(ss >> X)) continue;

        long long delta = 0;
        bool isVIP = false;

        if (X == "VIP" || X == "Vip" || X == "vip") {
            isVIP = true;
            delta = 1;
        } else {
            try {
                delta = stoll(X);
            } catch (...) {
                delta = 0;
            }
            isVIP = false;
        }

        auto printBlank = []() { cout << "\n"; };

        if (isEnter) {
            if (isVIP) {
                inside += 1;
                cout << 1 << " pessoas entraram na casa. Atualmente ha " << inside << " pessoas no evento.";
                printBlank();
                continue;
            } else {
                if (inside < N) {
                    long long can = min(delta, N - inside);
                    if (can > 0) {
                        inside += can;
                        cout << can << " pessoas entraram na casa. Atualmente ha " << inside << " pessoas no evento.";
                        printBlank();
                    } else {
                        cout << "Infelizmente a casa esta lotada, " << delta << " pessoas foram redirecionadas para a fila.\n";
                        q += delta;
                        cout << "A fila agora contem " << q << " pessoas.";
                        printBlank();
                    }
                    if (can < delta) {
                        long long red = delta - can;
                        q += red;
                        cout << "Infelizmente a casa esta lotada, " << red << " pessoas foram redirecionadas para a fila.";
                        cout << "\n";
                        cout << "A fila agora contem " << q << " pessoas.";
                        printBlank();
                    }
                } else {
                    cout << "Infelizmente a casa esta lotada, " << delta << " pessoas foram redirecionadas para a fila.\n";
                    q += delta;
                    cout << "A fila agora contem " << q << " pessoas.";
                    printBlank();
                }
            }
        } else {
            long long leaving = delta;
            long long actual = min(leaving, inside);
            inside -= actual;

            cout << actual << " pessoas sairam da casa. Atualmente ha " << inside << " pessoas no evento.";
            printBlank();

            if (q > 0) {
                long long can = min(q, N - inside);
                if (can > 0) {
                    q -= can;
                    inside += can;
                    cout << can << " pessoas da fila entraram na casa.\n";
                    cout << "A fila agora contem " << q << " pessoas.";
                    printBlank();
                } else {
                    cout << "Todos que estavam na fila de espera conseguiram entrar, atualmente nao ha fila de espera.";
                    printBlank();
                }

                if (q == 0) {
                    cout << "Todos que estavam na fila de espera conseguiram entrar, atualmente nao ha fila de espera.";
                    printBlank();
                } else {
                    if (N - inside == 0) {
                        continue;
                    }
                }
            }
        }
    }

    cout << "Vai Troinha, agora pede o ubii!";
    return 0;
}