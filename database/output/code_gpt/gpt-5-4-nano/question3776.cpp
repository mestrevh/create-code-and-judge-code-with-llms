/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

void mmm(int lista[20], int *menor, int *maior, float *média) {
    int mn = lista[0], mx = lista[0];
    long long sum = lista[0];
    for (int i = 1; i < 20; i++) {
        mn = min(mn, lista[i]);
        mx = max(mx, lista[i]);
        sum += lista[i];
    }
    *menor = mn;
    *maior = mx;
    *média = (mx + mn) / 2.0f;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int lista[20];
    for (int i = 0; i < 20; i++) {
        if (!(cin >> lista[i])) return 0;
    }

    int menor, maior;
    float media;
    mmm(lista, &menor, &maior, &media);

    cout << maior << ' ' << menor << "\n";
    cout << fixed << setprecision(1) << media << "\n";
    return 0;
}