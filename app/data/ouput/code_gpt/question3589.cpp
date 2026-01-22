/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int nota_objetiva, nota_redacao;
    char sexo;
    int total_candidatos = 0, candidatos_aprovados = 0;
    int mulheres_aprovadas = 0, homens_aprovados = 0;

    while (true) {
        cin >> nota_objetiva;
        if (nota_objetiva < 0) break;

        if (nota_objetiva > 100) {
            cout << "Digite uma nota inferior a 100." << endl;
            continue;
        }

        cin >> nota_redacao;
        if (nota_redacao > 100) {
            cout << "Digite uma nota inferior a 100." << endl;
            continue;
        }
        
        cin >> sexo;
        total_candidatos++;

        if (nota_objetiva >= 40 && nota_redacao >= 40) {
            double media = (nota_objetiva + nota_redacao) / 2.0;
            if (media >= 60) {
                candidatos_aprovados++;
                if (sexo == 'F') mulheres_aprovadas++;
                else if (sexo == 'M') homens_aprovados++;
            }
        }
    }

    cout << total_candidatos << " candidato(s) inscrito(s)." << endl;
    cout << candidatos_aprovados << " candidato(s) aprovado(s)." << endl;
    cout << mulheres_aprovadas << " mulher(es) e " << homens_aprovados << " homem(ns)." << endl;

    return 0;
}
