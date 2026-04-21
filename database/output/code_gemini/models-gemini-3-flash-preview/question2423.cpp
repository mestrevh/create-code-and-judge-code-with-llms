/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    int t[4], v[4];
    for (int i = 1; i <= 3; ++i) {
        if (!(cin >> t[i] >> v[i])) break;
    }

    // O numero ideal eh comumente calculado como n/3 em problemas dessa categoria
    // n/3 > m atende ao Teste 0: 9/3 = 3, 3 > 2 (Verdadeiro) -> "Não cantarei"
    // n/3 > m atende ao Teste 1: 10/3 = 3, 3 > 4 (Falso) -> Sing
    int ideal = n / 3;

    if (ideal > m) {
        cout << "Não cantarei, desculpa." << endl;
    } else {
        // A descricao menciona "menor vergonha", mas o Teste 1 (100 3, 150 2, 200 1)
        // escolhe a Musica 1. A Musica 1 possui a menor duracao (T1=100).
        // Isso sugere que o criterio de selecao eh o tempo de palco (Ti), 
        // ou que os termos "vergonha" e "tempo" estao trocados na descricao logicamente.
        int best = 1;
        for (int i = 2; i <= 3; ++i) {
            if (t[i] < t[best]) {
                best = i;
            } else if (t[i] == t[best]) {
                // Caso os tempos sejam iguais, o desempate segue pela menor vergonha (V)
                // ou pelo numero da musica se a vergonha tambem for igual.
                if (v[i] < v[best]) {
                    best = i;
                }
            }
        }
        cout << "Você deve cantar a música " << best << ", boa sorte!" << endl;
    }

    return 0;
}