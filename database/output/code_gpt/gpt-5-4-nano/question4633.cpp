/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long idade;
    long long soma = 0, qtd = 0;

    while (cin >> idade) {
        if (idade == 0) break;
        soma += idade;
        qtd++;
    }

    if (qtd == 0) return 0;

    double media = (double)soma / (double)qtd;
    long long mediaArred = llround(media);

    cout << "media de idade da turma: " << mediaArred << "\n";

    if (mediaArred >= 0 && mediaArred <= 25) cout << "jovem";
    else if (mediaArred >= 26 && mediaArred <= 60) cout << "adulta";
    else cout << "idosa";

    return 0;
}