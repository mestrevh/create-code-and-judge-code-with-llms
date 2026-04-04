/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

void mmm(int lista[20], int *menor, int *maior, float *media) {
    *menor = lista[0];
    *maior = lista[0];
    for (int i = 1; i < 20; ++i) {
        if (lista[i] < *menor) {
            *menor = lista[i];
        }
        if (lista[i] > *maior) {
            *maior = lista[i];
        }
    }
    *media = (*maior + *menor) / 2.0f;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int lista[20];
    for (int i = 0; i < 20; ++i) {
        if (!(cin >> lista[i])) break;
    }

    int menor, maior;
    float media;

    mmm(lista, &menor, &maior, &media);

    cout << maior << " " << menor << "\n";
    cout << fixed << setprecision(1) << media << "\n";

    return 0;
}