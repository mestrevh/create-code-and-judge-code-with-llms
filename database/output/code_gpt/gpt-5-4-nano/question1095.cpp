/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double media;
    string nome;
    int idade;
    char curso;

    vector<string> alunosPorIdadeMenor;
    bool firstYoung = true;
    int youngIdade = 0;
    string youngNome;

    int aprovFilosofia = 0;
    int aprovados = 0;
    int maioresSociologiaNaoAprov = 0;

    while (cin >> media) {
        if (media < 0) break;
        if (!(cin >> nome >> idade >> curso)) return 0;

        if (firstYoung) {
            youngIdade = idade;
            youngNome = nome;
            firstYoung = false;
        } else {
            if (idade < youngIdade) {
                youngIdade = idade;
                youngNome = nome;
            }
        }

        bool aprovado = (media >= 70);
        if (aprovado) {
            aprovados++;
            if (curso == 'f') aprovFilosofia++;
        } else {
            if (curso == 's' && idade >= 18) maioresSociologiaNaoAprov++;
        }
    }

    cout << "Quantidade de alunos de filosofia aprovados : " << aprovFilosofia << "\n";
    cout << "O nome da pessoa mais jovem : " << (firstYoung ? string("") : youngNome) << "\n";
    cout << "Quantidade de aprovados : " << aprovados << "\n";
    cout << "Quantidade pessoas maiores de idade nao aprovadas em sociologia : " << maioresSociologiaNaoAprov << "\n";

    return 0;
}