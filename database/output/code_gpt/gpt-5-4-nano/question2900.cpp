/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    long long incubadora = 0;
    queue<long long> fila;
    long long filaCount = 0;

    auto imprimirBranco = [&]() {
        cout << "\n";
    };

    auto tentarEntradaFila = [&]() {
        while (filaCount > 0 && incubadora < N) {
            long long can = min(filaCount, (long long)N - incubadora);
            incubadora += can;
            filaCount -= can;
            if (filaCount == 0) break;
            break;
        }
    };

    auto promoverFilaParaIncubadora = [&]() {
        if (filaCount <= 0) return;
        if (incubadora == N) return;

        long long before = filaCount;
        long long beforeInc = incubadora;

        long long canEnter = min(filaCount, (long long)N - incubadora);
        incubadora += canEnter;
        filaCount -= canEnter;

        cout << canEnter << " ovos da fila entraram na incubadora.\n";
        if (canEnter == before) {
            cout << "Todos que estavam na fila de espera conseguiram entrar, atualmente nao ha fila de espera.\n";
        } else {
            cout << "A fila agora contem " << filaCount << " ovos.\n";
        }
    };

    auto imprimirMensagemFinal = [&]() {
        bool raros = false;
        bool comuns = false;

        queue<long long> q = fila;
        while (!q.empty()) {
            q.pop();
        }

        if (incubadora > 0) {
            if (incubadora == 1) {
                raros = true;
                comuns = true;
            } else {
                raros = true;
                comuns = true;
            }
        }

        if (incubadora == 0) {
            cout << "Nao restou nenhum Pokemon na incubadora.";
            return;
        }

        if (incubadora < N) {
            if (incubadora == 0) {
                cout << "Nao restou nenhum Pokemon na incubadora.";
            } else {
                cout << "Restaram Pokemon raros e comuns na incubadora.";
            }
        } else {
            cout << "Restaram apenas Pokemon raros na incubadora.";
        }
    };

    string s1, s2;
    while (cin >> s1) {
        if (s1 == "Entraram") {
            cin >> s2;
            if (s2 == "SHINY") {
                imprimirBranco();
                if (true) {
                    incubadora += 1;
                    cout << "Um SHINY entrou na incubadora. Atualmente ha " << incubadora << " ovos na incubadora.\n";
                }
                continue;
            } else {
                long long X = stoll(s2);
                imprimirBranco();
                if (incubadora + X <= N) {
                    incubadora += X;
                    cout << X << " ovos entraram na incubadora. Atualmente ha " << incubadora << " ovos na incubadora.\n";
                } else {
                    long long enviados = max(0LL, (long long)N - incubadora);
                    long long exced = X - enviados;
                    if (enviados > 0) incubadora += enviados;
                    cout << "Infelizmente a incubadora esta lotada, " << exced << " ovos foram redirecionadas para a fila.\n";
                    filaCount += exced;
                    cout << "A fila agora contem " << filaCount << " ovos.\n";
                }
                continue;
            }
        } else if (s1 == "Sairam") {
            cin >> s2;
            if (s2 == "SHINY") {
                imprimirBranco();
                if (incubadora > 0) incubadora -= 1;
                cout << "Um SHINY nasceu. Atualmente ha " << incubadora << " ovos na incubadora.\n";
                if (filaCount > 0 && incubadora < N) {
                    long long canEnter = min(filaCount, (long long)N - incubadora);
                    if (canEnter > 0) {
                        long long before = filaCount;
                        incubadora += canEnter;
                        filaCount -= canEnter;
                        cout << canEnter << " ovos da fila entraram na incubadora.\n";
                        if (filaCount == 0) {
                            cout << "Todos que estavam na fila de espera conseguiram entrar, atualmente nao ha fila de espera.\n";
                        } else {
                            cout << "A fila agora contem " << filaCount << " ovos.\n";
                        }
                    }
                }
                continue;
            } else {
                long long X = stoll(s2);
                imprimirBranco();
                long long saidas = min(X, incubadora);
                incubadora -= saidas;
                cout << saidas << " ovos chocaram. Atualmente ha " << incubadora << " ovos na incubadora.\n";
                if (filaCount > 0 && incubadora < N) {
                    long long canEnter = min(filaCount, (long long)N - incubadora);
                    if (canEnter > 0) {
                        incubadora += canEnter;
                        filaCount -= canEnter;
                        cout << canEnter << " ovos da fila entraram na incubadora.\n";
                        if (filaCount == 0) {
                            cout << "Todos que estavam na fila de espera conseguiram entrar, atualmente nao ha fila de espera.\n";
                        } else {
                            cout << "A fila agora contem " << filaCount << " ovos.\n";
                        }
                    }
                }
                continue;
            }
        } else {
            break;
        }
    }

    int rareInside = 0;
    int totalInside = (int)incubadora;

    if (totalInside == 0) {
        cout << "Nao restou nenhum Pokemon na incubadora.";
    } else {
        if (rareInside > 0 && rareInside == totalInside) {
            cout << "Restaram apenas Pokemon raros na incubadora.";
        } else if (rareInside > 0) {
            cout << "Restaram Pokemon raros e comuns na incubadora.";
        } else {
            cout << "Restaram apenas Pokemon raros na incubadora.";
        }
    }

    return 0;
}