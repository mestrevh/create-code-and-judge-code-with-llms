/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

void formarRetangulo(int largura, int altura) {
    for (int i = 0; i < altura; i++) {
        for (int j = 0; j < largura; j++) cout << '*';
        if (i + 1 < altura) cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int largura, altura;
    if (!(cin >> largura >> altura)) return 0;
    formarRetangulo(largura, altura);
    return 0;
}