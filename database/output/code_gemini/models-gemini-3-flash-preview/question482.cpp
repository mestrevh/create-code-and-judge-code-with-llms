/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int entregas;
    int meta_cumprida = 0;
    int soma_total = 0;

    for (int i = 0; i < 7; ++i) {
        if (!(cin >> entregas)) break;
        if (entregas >= 100) {
            meta_cumprida++;
        }
        soma_total += entregas;
    }

    int media = soma_total / 7;

    cout << meta_cumprida << "\n" << media << endl;

    return 0;
}