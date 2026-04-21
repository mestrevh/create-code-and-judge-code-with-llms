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

    vector<string> a(N, string(N, 'x'));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char c;
            cin >> c;
            a[i][j] = c;
        }
    }

    auto get = [&](int i, int j) -> char {
        if (i < 0 || i >= N || j < 0 || j >= N) return 'x';
        return a[i][j];
    };

    bool condBranco = false;
    bool condAmarelo = false;
    bool condLaranja = false;
    bool condVermelho = false;

    for (int j = 0; j < N && !condBranco; j++) {
        if (j % 2 == 0) {
            for (int i = 0; i < N; i++) {
                if (a[i][j] == 'g') {
                    condBranco = true;
                    break;
                }
            }
        } else {
            for (int i = 0; i < N; i++) {
                if (a[i][j] == 'p') {
                    condBranco = true;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < N && !condAmarelo; i++) {
        int cnt = 0;
        for (int j = 0; j < N; j++) {
            if (a[i][j] == 's') cnt++;
        }
        if (cnt >= 2) condAmarelo = true;
    }

    for (int i = 0; i < N && !condLaranja; i++) {
        if (a[i][i] == 'i' || a[i][N - 1 - i] == 'i') condLaranja = true;
    }

    int enemies = 0, suspects = 0;
    int guardsOuter = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (a[i][j] == 'i') enemies++;
            if (a[i][j] == 's') suspects++;
            bool outer = (i == 0 || i == N - 1 || j == 0 || j == N - 1);
            if (outer && a[i][j] == 'g') guardsOuter++;
        }
    }
    if (enemies + suspects > guardsOuter) condVermelho = true;

    bool any = condBranco || condAmarelo || condLaranja || condVermelho;
    if (!any) {
        cout << "AZUL";
        return 0;
    }

    string ans;
    if (condBranco) ans = "BRANCO";
    else if (condAmarelo) ans = "AMARELO";
    else if (condLaranja) ans = "LARANJA";
    else if (condVermelho) ans = "VERMELHO";

    cout << "TRANSPARENTE";
    return 0;
}