/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char key[] = {'A', 'B', 'C', 'D', 'E', 'E', 'D', 'C', 'B', 'A'};
    char ans;

    while (cin >> ans) {
        int score = 0;
        for (int i = 1; i <= 10; ++i) {
            if (i > 1 && !(cin >> ans)) break;
            cout << "Insira a resposta do aluno para a pergunta " << i << ":\n";
            if (ans == key[i - 1]) {
                score++;
            }
        }
        cout << "Nota do aluno: " << score << "\n";
    }

    return 0;
}