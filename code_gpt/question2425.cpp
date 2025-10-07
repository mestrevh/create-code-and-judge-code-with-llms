/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    string assento1, assento2, assento3_opt1, assento3_opt2;
    int aluno_primeiros_socorros;

    cin >> assento1 >> assento2 >> aluno_primeiros_socorros >> assento3_opt1 >> assento3_opt2;

    int distancia_opt1 = abs(assento1[0] - assento3_opt1[0]);
    int distancia_opt2 = abs(assento2[0] - assento3_opt2[0]);

    bool prioridade_opt1 = (aluno_primeiros_socorros == 1);
    bool prioridade_opt2 = (aluno_primeiros_socorros == 2);

    if (distancia_opt1 < distancia_opt2 || (distancia_opt1 == distancia_opt2 && prioridade_opt1)) {
        cout << "A opcao 1 e a mais segura" << endl;
    } else if (distancia_opt2 < distancia_opt1 || (distancia_opt1 == distancia_opt2 && prioridade_opt2)) {
        cout << "A opcao 2 e a mais segura" << endl;
    } else {
        cout << "Vou fechar os olhos e decidir" << endl;
    }

    return 0;
}
