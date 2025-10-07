/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <map>
using namespace std;

struct Aluno {
    string nome;
    int idade;
    char curso;
    float media;
};

int main() {
    map<int, Aluno> alunos;
    string nome;
    int idade;
    char curso;
    float media;
    int qtd_filosofia_aprovados = 0, qtd_aprovados = 0, qtd_sociologia_maior_nao_aprovados = 0;
    string nome_mais_jovem;
    int menor_idade = 101; // Considera idades até 100
    
    while (true) {
        cin >> media;
        if (media < 0) break;
        cin >> nome >> idade >> curso;

        if (alunos.count(idade) == 0) {
            alunos[idade] = {nome, idade, curso, media};
        }

        if (media >= 70) {
            qtd_aprovados++;
            if (curso == 'f') qtd_filosofia_aprovados++;
        } else if (curso == 's' && idade >= 18) {
            qtd_sociologia_maior_nao_aprovados++;
        }
        
        if (idade < menor_idade) {
            menor_idade = idade;
            nome_mais_jovem = nome;
        }
    }

    cout << "Quantidade de aprovados em filosofia : " << qtd_filosofia_aprovados << endl;
    if (!nome_mais_jovem.empty()) {
        cout << "O nome da pessoa mais jovem : " << nome_mais_jovem << endl;
    }
    cout << "Quantidade de aprovados : " << qtd_aprovados << endl;
    cout << "Quantidade pessoas maiores de idade nao aprovadas em sociologia : " << qtd_sociologia_maior_nao_aprovados << endl;

    return 0;
}
